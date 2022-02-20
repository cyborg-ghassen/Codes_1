#include <stdio.h>

int min(int[], int);
int max(int[], int);
int indexPremOcc(int[], int, int);
void indexAllOcc(int[], int, int);
int pos_occ_rec1(int T[], int n, int x, int d);
int pos_occ_rec2(int[], int, int);
int dichotomy(int[], int, int);
int recherche_dicho_rec(int[], int, int, int);

int main() {
    printf("**************************** TP 1 ****************************\n");
    const int n = 5;
    int T[n], location, minimum, maximum;
    printf("\nFirst fill the array with %d integers: ", n);
    for (int i = 1; i <= n; i++) {
        printf("\nElement %d: ", i);
        scanf("%d", &T[i]);
    }

    int num;
    printf("\nEnter the number of question: ");
    scanf("%d", &num);
    int a, x;
    switch (num) {
        case 1:
            location = min(T, n);
            minimum  = T[location];
            printf("\n The min is %d", minimum); break;
        case 2:
            location = max(T, n);
            maximum  = T[location];
            printf("\n The max is %d", maximum); break;
        case 3:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("The index of first occurrence is %d", indexPremOcc(T, n, x)); break;
        case 4:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("The indexes of all occurrences are: ");
            indexAllOcc(T, n, x); break;
        case 5:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("The index of first occurrence is %d", pos_occ_rec1(T, n, x, 0)); break;
        case 6:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("The index of the last occurrence is %d", pos_occ_rec2(T, n, x)); break;
        case 7:
            printf("Enter element to search: ");
            scanf("%d", &x);
            printf("Element %d", dichotomy(T, n, x)); break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &x);
            printf("Element %d", recherche_dicho_rec(T, x, 0, n)); break;
        default:
            printf("\n This question does not exist"); break;
    }

    return 0;
}

int min(int a[], int n) {
    printf("\n********************* Minimum in an array *********************\n");
    int c, index = 0;

    for (c = 1; c <= n; c++) {
        if (a[c] < a[index])
            index = c;
    }

    return index;
}

int max(int a[], int n) {
    printf("\n********************* Maximum in an array *********************\n");
    int c, index = 0;

    for (c = 1; c <= n; c++) {
        if (a[c] > a[index])
            index = c;
    }

    return index;
}

int indexPremOcc(int T[], int n, int x){
    printf("\n********************* First occurrence *********************\n");
    for (int i = 0; i < n; i++) {
        if (T[i] == x)
            return i;
    }
    return -99;
}

void indexAllOcc(int T[], int n, int x){
    printf("\n********************* All occurrences *********************\n");
    for (int i = 0; i <= n; i++) {
        if (T[i] == x)
            printf("%d\t", i);
    }
}

int pos_occ_rec1(int T[], int n, int x, int d){
    printf("\n********************* Recursive first occurrence *********************\n");
    if (d == n)
        return d;
    return pos_occ_rec1(T, n, x, d + 1);
}

int pos_occ_rec2(int T[], int n, int x){
    printf("\n********************* Recursive last occurrence *********************\n");
    if (T[x] == T[n])
        return n;
    else
        return pos_occ_rec2(T, n - 1, x);
}

int dichotomy(int T[], int n, int x){
    printf("\n********************* Dichotomy search *********************\n");
    int a = 0;
    int b = n - 1;
    while (a <= b){
        int m = (int)(a + b) / 2;
        if (T[m] == x)
            return m;
        else if (T[m] < x)
            a = m + 1;
        else
            b = m - 1;
    }
    return -1;
}

int recherche_dicho_rec(int T[], int x, int d, int f){
    printf("\n********************* Recursive dichotomy search *********************\n");
    if (f >= d)
    {
        int mid = d + (f - d)/2;
        if (T[mid] == x)  return mid;
        if (T[mid] > x) return recherche_dicho_rec(T, x, d, mid-1);
        return recherche_dicho_rec(T, x, mid+1, f);
    }
    return -1;
}
