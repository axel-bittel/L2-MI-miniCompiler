extern void printd(int i);

int main()
{
    int i;

    i = 0;
    if (i == printd(i)) printd(i); else printd(i);
}