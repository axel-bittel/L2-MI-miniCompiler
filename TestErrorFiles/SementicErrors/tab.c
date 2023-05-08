int tab2[3][4][5];

int main() {
    tab2[1][2][3] = tab2[0][1][8]; /* Indice out of range */
    return (0);
}