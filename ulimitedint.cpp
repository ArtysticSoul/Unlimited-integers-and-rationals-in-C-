/* Do NOT add/bachahuaove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedint.h"

// drone, bachahua, siz2, bhsiz
int bdachhota(int* a,int* b, int n1, int n2){
    if(n1>n2){
        return 1;
    }
    else if(n2>n1){
        return -1;
    }
    else{
        for(int i=0 ; i<n1 ; i++){
            if(a[i]>b[i]){
                return 1;
            }
            else if(a[i]<b[i]){
                return -1;
            }
        }
    }
    return 0;
}

UnlimitedInt* convertsign(int* a, int n, int sin){
    int* arr=new int[n];
    for(int i=0 ; i<n ; i++){
        arr[i]=a[i];
    }
    UnlimitedInt* ans=new UnlimitedInt(arr,n,sin,n);
    return ans;
}

void backtofront(int* &a, int n){
    int i=0;
    int j=n-1;
    while(i<j){
        int x=a[i];
        a[i]=a[j];
        a[j]=x;
        i++;
        j--;
    }
}

UnlimitedInt *fndans(UnlimitedInt *a, UnlimitedInt *b, UnlimitedInt *&c)
{
    UnlimitedInt *faltu1=new UnlimitedInt();
    UnlimitedInt *faltu2=new UnlimitedInt();
    int sin1=a->get_sign();
    int siz1=a->get_size();
    int *first=a->get_array();
    int sin2=b->get_sign();
    int siz2=b->get_size();
    int *second=b->get_array();
    UnlimitedInt **arre=new UnlimitedInt *[10];
    arre[0]=new UnlimitedInt();
    int i=1;
    while (i < 10)
    {
        arre[i]=arre[0]->add(b, arre[i-1]);
        i++;
    }
    backtofront(first,siz1);
    backtofront(second,siz2);
    for (int k=0; k<10; k++)
    {
        int* last=(arre[k])->get_array();
        backtofront(last,arre[k]->get_size());
    }
    int *ans=new int[siz1];
    int *drone;
    int xyzw=0;
    int okay=0;
    int *bachahua=new int[1];
    int bhsiz=1;
    bachahua[0]=first[0];
    int yz;
    for (; xyzw < siz1; xyzw++)
    {
        drone=arre[1]->get_array();
        yz=bdachhota(drone, bachahua, siz2, bhsiz);
        if (yz > 0)
        {
            ans[okay]=0;
            okay++;
            if (okay >= siz1)
                break;
            if (bachahua[0] != 0)
            {
                int *stun=new int[bhsiz + 1];
                for (int k=0; k<bhsiz; k++)
                {
                    stun[k]=bachahua[k];
                }
                stun[bhsiz]=first[okay];
                delete[] bachahua;
                bachahua=stun;
                bhsiz++;
            }
            else
            {
                bachahua[0]=first[okay];
            }
        }
        else
        {
            int hukka;
            for (hukka=9; hukka >= 1; hukka--)
            {
                drone=arre[hukka]->get_array();
                yz=bdachhota(drone, bachahua, arre[hukka]->get_size(), bhsiz);
                if (yz <= 0)
                    break;
            }
            ans[okay]=hukka;
            okay++;
            backtofront(bachahua, bhsiz);
            faltu1=new UnlimitedInt(bachahua, bhsiz, 1, bhsiz);
            backtofront(drone, arre[hukka]->get_size());
            faltu2=new UnlimitedInt(drone, arre[hukka]->get_size(), 1, arre[hukka]->get_size());
            bachahua=faltu1->sub(faltu1, faltu2)->get_array();
            bhsiz=faltu1->sub(faltu1, faltu2)->get_size();
            backtofront(drone, arre[hukka]->get_size());
            backtofront(bachahua, bhsiz);
            if (okay >= siz1)
                break;
            if (bachahua[0] != 0)
            {
                int *stun=new int[bhsiz + 1];
                for (int ii=0; ii < bhsiz; ii++)
                {
                    stun[ii]=bachahua[ii];
                }
                stun[bhsiz]=first[okay];
                delete[] bachahua;
                bachahua=stun;
                bhsiz++;
            }
            else
            {
                bachahua[0]=first[okay];
            }
        }
    }
    backtofront(ans, siz1);
    backtofront(bachahua, bhsiz);
    c=new UnlimitedInt(bachahua, bhsiz, 1, bhsiz);
    for (i=siz1 - 1; i >= 0; i--)
    {
        if (ans[i] != 0)
            break;
    }
    if(i>=0){
        int *lrkey=new int[i + 1];
        for (int j=0; j < i + 1; j++)
        {
            lrkey[j]=ans[j];
        }
        delete[] ans;
        ans=lrkey;
        UnlimitedInt *returningit=new UnlimitedInt(ans, i + 1, 1, i + 1);
        for(int i=0 ; i<10 ; i++){
            delete arre[i];
        }
        delete []arre;
        return returningit;
    }
    else{
        UnlimitedInt *returningit=new UnlimitedInt();
        for(int i=0 ; i<10 ; i++){
            delete arre[i];
        }
        delete []arre;
        return returningit;
    }
}

UnlimitedInt *UnlimitedInt::div(UnlimitedInt *i1, UnlimitedInt *i2)
{
    int sin1=i1->get_sign();
    int sin2=i2->get_sign();
    int siz1=i1->get_size();
    int siz2=i2->get_size();
    int *i1rr=i1->get_array();
    int *i2rr=i2->get_array();
    if ((sin1*sin2>0 && siz1<siz2) || sin1==0)
    {
        UnlimitedInt *ans=new UnlimitedInt();
        return ans;
    }
    else if(sin1*sin2<0 && siz1<siz2){
        UnlimitedInt *ans=new UnlimitedInt("-1");
        return ans;
    }
    int *arr1=new int[siz1];
    int *arr2=new int[siz2];
    for (int i=0; i < siz1; i++)
    {
        arr1[i]=i1rr[i];
    }
    for (int i=0; i < siz2; i++)
    {
        arr2[i]=i2rr[i];
    }
    UnlimitedInt *i3=new UnlimitedInt(arr1, siz1, 1, siz1);
    UnlimitedInt *i4=new UnlimitedInt(arr2, siz2, 1, siz2);
    if ((sin1*sin2)>0)
    {
        UnlimitedInt *lft=new UnlimitedInt();
        UnlimitedInt *ans=fndans(i3, i4, lft);
        delete i3;
        delete i4;
        delete lft;
        return ans;
    }
    else
    {
        UnlimitedInt *ans=new UnlimitedInt();
        UnlimitedInt *lft=new UnlimitedInt();
        ans=fndans(i3, i4, lft);
        if ((lft->to_string())!="0")
        {
            UnlimitedInt *extra=new UnlimitedInt("1");
            ans=ans->add(ans, extra);
            UnlimitedInt* returningit=new UnlimitedInt(ans->get_array(),ans->get_size(),-1,ans->get_size());
            delete i3;
            delete i4;
            delete lft;
            delete extra;
            return returningit;
        }
        else
        {
            UnlimitedInt* returningit=new UnlimitedInt(ans->get_array(),ans->get_size(),-1,ans->get_size());
            delete i3;
            delete i4;
            delete lft;
            return returningit;
        }
    }
}

bool Comparison(UnlimitedInt* i1, UnlimitedInt* i2){
    int i1s=i1->get_size();
    int i2s=i2->get_size();
    int* i1rr=i1->get_array();
    int* i2rr=i2->get_array();
    if(i1s>i2s){
        return true;
    }
    else if(i2s>i1s){
        return false;
    }
    else{
        for(int i=0 ; i<i1s ; i++){
            if(i1rr[i1s-i-1]>i2rr[i1s-i-1]){
                return true;
            }
            else if(i1rr[i1s-i-1]<i2rr[i1s-i-1]){
                return false;
            }
        }
    }
    return true;
}

UnlimitedInt::UnlimitedInt(){
    size=1;
    sign=0;
    capacity=size;
    unlimited_int=new int [1];
    unlimited_int[0]=0;
}

UnlimitedInt::UnlimitedInt(string s){
    long long n=s.length();
    size=n;
    char ch=s[0];
    if(ch=='-'){
        sign=-1;
        size--;
    }//check for "000000" && "-0000000";
    else if(s[0]=='0' || (s[0]=='-' && s[1]=='0')){
        sign=0;
    }
    else{
        sign=1;
    }
    capacity=size;
    unlimited_int=new int[capacity];
    for(int i=0 ; i<size ; i++){
        if(sign==-1){
            char c=s[size-i];
            int x=c-'0';
            unlimited_int[i]=x; 
        }
        else{
            char c=s[size-i-1];
            int x=c-'0';
            unlimited_int[i]=x;
        }
    }
} // Create from            string 

UnlimitedInt::UnlimitedInt(int i){
    if(i==0){
        sign=0;
    }
    else if(i>0){
        sign=1;
    }
    else{
        sign=-1;
    }
    i=abs(i);
    int j=i;
    while(j>0){
        j/=10;
        size++;
    }
    if(i==0){
        size=1;
    }
    capacity=size;
    unlimited_int=new int[capacity];
    for(int k=0 ; k<size ; k++){
        int x=i%10;
        unlimited_int[k]=x;
        i/=10;
    }
} // Create from int

UnlimitedInt::UnlimitedInt(int* ulimited_int, int cap, int sgn, int sz){
    sign=sgn;
    size=sz;
    capacity=cap;
    unlimited_int=ulimited_int;
} // Complete constructor

UnlimitedInt::~UnlimitedInt(){
    delete []unlimited_int;
}

// Return the size of the unlimited int
int UnlimitedInt::get_size(){
    return size;
}

// Return the unlimited_int array
int* UnlimitedInt::get_array(){
    return unlimited_int;
} 

// Get sign
int UnlimitedInt::get_sign(){
    return sign;
}

int UnlimitedInt::get_capacity(){
    return capacity;
}

// Implement these integer operations as they are defined for integers in mathematics
// (Since there are no size restrictions)
UnlimitedInt* UnlimitedInt::add(UnlimitedInt* i1, UnlimitedInt* i2){
    if(i1->get_sign()==0){
        int cpct=i2->get_capacity();
        int sin=i2->get_sign();
        int siz=i2->get_size();
        int* brr=i2->get_array();
        int* arr=new int [cpct];
        for(int i=0 ; i<siz ; i++){
            arr[i]=brr[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if(i2->get_sign()==0){
        int cpct=i1->get_capacity();
        int sin=i1->get_sign();
        int siz=i1->get_size();
        int* brr=i1->get_array();
        int* arr=new int [cpct];
        for(int i=0 ; i<siz ; i++){
            arr[i]=brr[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if((i1->get_sign()>0 && i2->get_sign()>0) || (i1->get_sign()<0 && i2->get_sign()<0)){
        int i1s=i1->get_size();
        int i2s=i2->get_size();
        int cpct=max(i2->get_capacity(),i1->get_capacity()) + 1;
        int sin=i2->get_sign();
        int siz=max(i2s,i1s) + 1;
        int* i1rr=i1->get_array();
        int* i2rr=i2->get_array();
        int* arr=new int [cpct];
        int carry=0;
        for(int i=0 ; i<siz ; i++){
            int a;
            int b;
            if(i<i1s){
                a=i1rr[i];
            }
            else{
                a=0;
            }
            if(i<i2s){
                b=i2rr[i];
            }
            else{
                b=0;
            }
            int c=a+b+carry;
            carry=c/10;
            c=c%10;
            arr[i]=c;
        }
        if(arr[siz-1]==0){
            siz--;
            cpct--;
            int * temp=new int [siz];
            for(int i=0 ; i<siz ; i++){
                temp[i]=arr[i];
            }
            delete []arr;
            arr=temp;
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if(i1->get_sign()<0){
        int cpct=i1->get_capacity();
        int sin=1;
        int siz=i1->get_size();
        int* brr=i1->get_array();
        int* arr=new int [cpct];
        for(int i=0 ; i<siz ; i++){
            arr[i]=brr[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        UnlimitedInt* i4=sub(i2,i3);
        delete i3;
        return i4;
    }
    int cpct=i2->get_capacity();
    int sin=1;
    int siz=i2->get_size();
    int* brr=i2->get_array();
    int* arr=new int [cpct];
    for(int i=0 ; i<siz ; i++){
        arr[i]=brr[i];
    }
    UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
    UnlimitedInt* i4=sub(i1,i3);
    delete i3;
    return i4;
}

UnlimitedInt* UnlimitedInt::sub(UnlimitedInt* i1, UnlimitedInt* i2){
    if(i1->get_sign()==0){
        int cpct=i2->get_capacity();
        int sin=-1;
        int siz=i2->get_size();
        int* brr=i2->get_array();
        int* arr=new int [cpct];
        for(int i=0 ; i<siz ; i++){
            arr[i]=brr[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if(i2->get_sign()==0){
        int cpct=i1->get_capacity();
        int sin=i1->get_sign();
        int siz=i1->get_size();
        int* brr=i1->get_array();
        int* arr=new int [cpct];
        for(int i=0 ; i<siz ; i++){
            arr[i]=brr[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if(i1->get_sign()>0 && i2->get_sign()>0){
        int i1s=i1->get_size();
        int i2s=i2->get_size();
        int cpct=max(i2->get_capacity(),i1->get_capacity());
        int* i1rr=i1->get_array();
        int* i2rr=i2->get_array();
        int sin=0;
        if(i1s>i2s){
            sin=1;
        }
        else if(i2s>i1s){
            sin=-1;
        }
        else{
            for(int i=0 ; i<i1s ; i++){
                if(i1rr[i1s-i-1]>i2rr[i1s-i-1]){
                    sin=1;
                    break;
                }
                else if(i1rr[i1s-i-1]<i2rr[i1s-i-1]){
                    sin=-1;
                    break;
                }
            }
        }
        int siz=max(i2s,i1s);
        int* arr=new int [cpct];
        int carry=0;
        for(int i=0 ; i<siz ; i++){
            int a;
            int b;
            if(i<i1s){
                a=i1rr[i];
            }
            else{
                a=0;
            }
            if(i<i2s){
                b=i2rr[i];
            }
            else{
                b=0;
            }
            int c;
            if(sin>=0){
                c=a-b-carry;
            }
            else{
                c=b-a-carry;
            }
            if(c<0){
                carry=1;
                c+=10;
            }
            else{
                carry=0;
            }
            arr[i]=c;
        }
        int count=0;
        for(int i=0 ; i<siz ; i++){
            if(arr[siz-i-1]==0){
                count++;
            }
            else{
                break;
            }
        }
        siz-=count;
        if(siz==0){
            siz++;
        }
        cpct=siz;
        int * temp=new int [siz];
        for(int i=0 ; i<siz ; i++){
            temp[i]=arr[i];
        }
        delete []arr;
        arr=temp;
        UnlimitedInt* i3=new UnlimitedInt(arr, cpct, sin, siz);
        return i3;
    }
    if(i1->get_sign()<0 && i2->get_sign()<0){
        int cpct1=i1->get_capacity();
        int sin1=1;
        int siz1=i1->get_size();
        int* brr1=i1->get_array();
        int* arr1=new int [cpct1];
        for(int i=0 ; i<siz1 ; i++){
            arr1[i]=brr1[i];
        }
        UnlimitedInt* i3=new UnlimitedInt(arr1, cpct1, sin1, siz1);
        int cpct2=i2->get_capacity();
        int sin2=1;
        int siz2=i2->get_size();
        int* brr2=i2->get_array();
        int* arr2=new int [cpct2];
        for(int i=0 ; i<siz2 ; i++){
            arr2[i]=brr2[i];
        }
        UnlimitedInt* i4=new UnlimitedInt(arr2, cpct2, sin2, siz2);
        UnlimitedInt* i5=sub(i4,i3);
        delete i3;
        delete i4;
        return i5;
    }
    if(i1->get_sign()>0 && i2->get_sign()<0){
        int cpct2=i2->get_capacity();
        int sin2=1;
        int siz2=i2->get_size();
        int* brr2=i2->get_array();
        int* arr2=new int [cpct2];
        for(int i=0 ; i<siz2 ; i++){
            arr2[i]=brr2[i];
        }
        UnlimitedInt* i4=new UnlimitedInt(arr2, cpct2, sin2, siz2);
        UnlimitedInt* i5=add(i1,i4);
        delete i4;
        return i5;
    }
    int cpct2=i2->get_capacity();
    int sin2=-1;
    int siz2=i2->get_size();
    int* brr2=i2->get_array();
    int* arr2=new int [cpct2];
    for(int i=0 ; i<siz2 ; i++){
        arr2[i]=brr2[i];
    }
    UnlimitedInt* i4=new UnlimitedInt(arr2, cpct2, sin2, siz2);
    UnlimitedInt* i5=add(i1,i4);
    delete i4;
    return i5;
}

UnlimitedInt* UnlimitedInt::mul(UnlimitedInt* i1, UnlimitedInt* i2){
    if(i1->get_sign()==0 || i2->get_sign()==0){
        UnlimitedInt* i3=new UnlimitedInt();
        return i3;
    }
    if(i1->get_size()<i2->get_size()){
        return mul(i2,i1);
    }
    UnlimitedInt** arre =new UnlimitedInt*[10];
    UnlimitedInt* x1=new UnlimitedInt();
    arre[0]=x1;
    for(int i=0 ; i<9 ; i++){
        arre[i+1]=add(i1,arre[i]);
    }
    int i2s=i2->get_size();
    int i1s=i1->get_size();
    int * result=new int[i1s+i2s];
    int * brr2=i2->get_array();
    for(int i=0; i<i1s+i2s ; i++){
        result[i]=0;
    }
    for(int i=0; i<i2s ; i++){
        int n=arre[brr2[i]]->get_size();
        int * adder=arre[brr2[i]]->get_array();
        int k=0;
        int carry=0;
        for(int j=i ; j<i1s+i2s ; j++){
            int a=result[j];
            int b;
            if(k<n){
                b=adder[k];
            }
            else{
                b=0;
            }
            int c=a+b+carry;
            carry=c/10;
            c%=10;
            result[j]=c;
            k++;
        }
    }
    int siz=i1s+i2s;
    if(result[i1s+i2s-1]==0){
        int * temp=new int[i1s+i2s-1];
        for(int i=0 ; i<i1s+i2s-1 ; i++){
            temp[i]=result[i];
        }
        delete []result;
        result=temp;
        siz--;
    }
    int sin=(i1->get_sign())*(i2->get_sign());
    int cpct=siz;
    UnlimitedInt* i3=new UnlimitedInt(result, cpct, sin, siz);
    for(int i=0 ; i<10 ; i++){
        delete arre[i];
    }
    delete []arre;
    return i3;
}

//r=a - (b * floor(a/b));
UnlimitedInt* UnlimitedInt::mod(UnlimitedInt* i1, UnlimitedInt* i2){
    UnlimitedInt* i3=div(i1,i2);
    UnlimitedInt* i4=mul(i2,i3);
    UnlimitedInt* i5=sub(i1,i4);
    delete i3;
    delete i4;
    return i5;
}

// Conversion Functions 
string UnlimitedInt::to_string(){
    string s;
    if(sign<0){
        s+='-';
    }
    for(int i=0 ; i<size ; i++){
        int t=unlimited_int[size-i-1];
        char ch=t+'0';
        s+=ch;
    }
    return s;
}
