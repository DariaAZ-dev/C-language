#include <stdio.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int tab[MAX];
    int top;
} pl;

void stack_init(pl *p) {
    p->top = -1;
}

int push(int val, pl *p) {
    if (p->top == MAX - 1) {
        return 0;
    }
    p->tab[++p->top] = val;
    return 1;
}

int pop(pl *p) {
    if (p->top == -1) {
        return 0;
    }
    p->top--;
    return 1;
}
//logic: put < in the stack if found an opening tag <...>
// put / in the stack if found a closing tag </...>

int findlast(pl *p) {
    // Check if there are at least 2 elements in the stack
    if (p->top < 1) {
        return 0;
    }

    // Since it's a stack, the "last" elements are at the top
    // If top is '/', we check if the one below it is '<'
    //delete <...> and </...> from the end of stack as soon as </...> appears in file
    // (if there is a <...> before </...>)
    if (p->tab[p->top] == '/' && p->tab[p->top - 1] == '<') {
        return 1;
    }

    return 0;
}

enum Etats {
    Start,
    foundopen,
    foundline
};

int automatecheck(FILE *fp) {
    pl pile;
    stack_init(&pile);
    int c;
    enum Etats now = Start;
    int error_count = 0; // The counter

    while ((c = fgetc(fp)) != EOF) {
        switch (now) {
            case Start:
                if (c == '<') now = foundopen;
                break;

            case foundopen:
                if (c == '/') {
                    now = foundline;
                } else {
                    if (!isalpha(c)) {
                        printf("Mistake: Tag name must start with a letter.\n");
                        error_count++;
                        // We skip to '>' to try and recover and keep counting
                        while (c != '>' && c != EOF) c = fgetc(fp);
                        now = Start;
                    } else {
                        push('<', &pile);
                        while (c != '>' && c != EOF) c = fgetc(fp);
                        now = Start;
                    }
                }
                break;

            case foundline:
                push('/', &pile);
                while (c != '>' && c != EOF) c = fgetc(fp);
                
                if (findlast(&pile) == 1) {
                    pop(&pile);
                    pop(&pile);
                } else {
                    printf("Mistake: Mismatched closing tag.\n");
                    error_count++;
                    // Clean up stack as best as possible to keep checking
                    pop(&pile); 
                }
                now = Start;
                break;
        }
    }

    // Final check for unclosed tags
    while (pile.top != -1) {
        error_count++;
        pop(&pile);
    }

    printf("\nTotal mistakes found: %d\n", error_count);
    return (error_count == 0); 
}

int main(void) {
    FILE *pFile;

    if ((pFile = fopen("fichier.txt", "rt"))) {
        automatecheck(pFile);
        fclose(pFile);
    } else {
        printf("erreur d'ouverture du fichier\n");
    }

    return 0;
}