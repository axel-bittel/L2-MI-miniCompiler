extern int printd( int i );

int f (int a, int b){
    return(0);
}

int f (){ //double declaration with the same type
    return (1);
}

int f2 (int a, int b){
    return(0);
}

void f2 (int c){ //double declaration with a different type
    printd(c);
}