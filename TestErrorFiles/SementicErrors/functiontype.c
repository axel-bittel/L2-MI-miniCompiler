extern int printd( int i );

void f(int a){
    printd(a);
    return (1);
}

void main(){
    int a;
    a = 2;
    f(2);
}