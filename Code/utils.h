strcpy(d,s)
char *d;
char *s;
{
    while(*s){
        *d=*s;
        d++;
        s++;
    }
    *d='\0';
}

strcat(s,t)
char *s;
char *t;
{
    while(*s) s++;
    while(*t){
        *s=*t;
        s++;
        t++;
    }
    *s='\0';
}

atoi(s)
char *s;
{
    int n=0;
    while(*s>='0' && *s<='9'){
        n = n*10 + (*s-'0');
        s++;
    }
    return n;
}

reverse(s)
char *s;
{
    char *e=s;
    char temp;
    while(*e) e++;
    e--;
    while(s<e){
        temp=*s;
        *s=*e;
        *e=temp;
        s++;
        e--;
    }
}

itoa(n,s)
int n;
char *s;
{
    int neg=0;
    char *start=s;

    if(n<0){
        neg=1;
        n=-n;
    }

    do{
        *s = n%10 + '0';
        s++;
    }while((n/=10)>0);

    if(neg){
        *s='-';
        s++;
    }

    *s='\0';
    reverse(start);
}