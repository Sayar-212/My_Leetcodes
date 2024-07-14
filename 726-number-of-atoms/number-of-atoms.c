#define MAX_ELEMENTS 1000

typedef struct {
    char element[3];
    int count;
} Element;

typedef struct {
    Element elements[MAX_ELEMENTS];
    int size;
} Counter;

typedef struct {
    Counter stack[MAX_ELEMENTS];
    int top;
} Stack;

void initCounter(Counter* counter) {
    counter->size = 0;
}

void addElement(Counter* counter, const char* element, int count) {
    for (int i = 0; i < counter->size; ++i) {
        if (strcmp(counter->elements[i].element, element) == 0) {
            counter->elements[i].count += count;
            return;
        }
    }
    strcpy(counter->elements[counter->size].element, element);
    counter->elements[counter->size].count = count;
    counter->size++;
}

void multiplyCounter(Counter* counter, int factor) {
    for (int i = 0; i < counter->size; ++i) {
        counter->elements[i].count *= factor;
    }
}

void mergeCounters(Counter* target, const Counter* source) {
    for (int i = 0; i < source->size; ++i) {
        addElement(target, source->elements[i].element, source->elements[i].count);
    }
}

void push(Stack* stack, const Counter* counter) {
    stack->stack[++stack->top] = *counter;
}

Counter pop(Stack* stack) {
    return stack->stack[stack->top--];
}

int compareElements(const void* a, const void* b) {
    return strcmp(((Element*)a)->element, ((Element*)b)->element);
}

char* countOfAtoms(char* formula) {
    int n = strlen(formula);
    Counter resultCounter;
    initCounter(&resultCounter);
    Stack parenthesisStack;
    parenthesisStack.top = -1;
    int curInd = 0;

    while (curInd < n) {
        char curChar = formula[curInd];

        if (curChar == '(') {
            curInd++;
            Counter newCounter;
            initCounter(&newCounter);
            push(&parenthesisStack, &newCounter);
            continue;
        }

        if (curChar == ')') {
            char mult[10] = "";
            curInd++;

            while (curInd < n && isdigit(formula[curInd])) {
                strncat(mult, &formula[curInd], 1);
                curInd++;
            }

            int multiplier = mult[0] ? atoi(mult) : 1;
            Counter lastCounter = pop(&parenthesisStack);
            multiplyCounter(&lastCounter, multiplier);
            Counter* target = parenthesisStack.top >= 0 ? &parenthesisStack.stack[parenthesisStack.top] : &resultCounter;
            mergeCounters(target, &lastCounter);
            continue;
        }

        char curElem[3] = "";
        char curCounter[10] = "";
        Counter* target = parenthesisStack.top >= 0 ? &parenthesisStack.stack[parenthesisStack.top] : &resultCounter;

        while (curInd < n && formula[curInd] != '(' && formula[curInd] != ')') {
            if (isalpha(formula[curInd])) {
                if (isupper(formula[curInd]) && curElem[0] != '\0') {
                    addElement(target, curElem, curCounter[0] ? atoi(curCounter) : 1);
                    curCounter[0] = '\0';
                    curElem[0] = '\0';
                }
                strncat(curElem, &formula[curInd], 1);
            } else {
                strncat(curCounter, &formula[curInd], 1);
            }
            curInd++;
        }

        addElement(target, curElem, curCounter[0] ? atoi(curCounter) : 1);
    }

    qsort(resultCounter.elements, resultCounter.size, sizeof(Element), compareElements);

    char* result = malloc(MAX_ELEMENTS * 10);
    result[0] = '\0';
    for (int i = 0; i < resultCounter.size; ++i) {
        strcat(result, resultCounter.elements[i].element);
        if (resultCounter.elements[i].count > 1) {
            char countStr[10];
            sprintf(countStr, "%d", resultCounter.elements[i].count);
            strcat(result, countStr);
        }
    }

    return result;
}