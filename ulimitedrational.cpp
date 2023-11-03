/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "ulimitedrational.h"
UnlimitedInt* hcf(UnlimitedInt* i1, UnlimitedInt* i2);

UnlimitedInt* hcf(UnlimitedInt* i1, UnlimitedInt* i2) {
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
    while (i4->get_sign()!= 0) {
        UnlimitedInt* temp = i4;
        i4 =i1->mod(i3,i4);
        i3 = temp;
    }
    int* check=i3->get_array();
    if(check[i3->get_size()-1]==0){
        UnlimitedInt* p=new UnlimitedInt("1");
        delete i3;
        i3=p;
    }
    return i3;
}

UnlimitedRational::UnlimitedRational(){
    p=new UnlimitedInt();
    q=new UnlimitedInt();
}

UnlimitedRational::UnlimitedRational(UnlimitedInt* num, UnlimitedInt* den){
    if(den->get_sign()==0){
        p=new UnlimitedInt();
        q=new UnlimitedInt();
    }
    else if(num->get_sign()==0){
        p=new UnlimitedInt();
        int cpct1=den->get_capacity();
        int sin1=den->get_sign();
        int siz1=den->get_size();
        int* brr1=den->get_array();
        int* arr1=new int [cpct1];
        for(int i=0 ; i<siz1 ; i++){
            arr1[i]=brr1[i];
        }
        UnlimitedInt* temp=new UnlimitedInt(arr1, cpct1, sin1, siz1);
        q=temp;
    }
    else{
        UnlimitedInt* g=hcf(num,den);
        p=num->div(num,g);
        q=num->div(den,g);
    }
}

UnlimitedRational::~UnlimitedRational(){
    delete p;
    delete q;
}

UnlimitedInt* UnlimitedRational::get_p(){
    return p;
}

UnlimitedInt* UnlimitedRational::get_q(){
    return q;
}

string UnlimitedRational::get_p_str(){
    string s=p->to_string();
    return s;
} // Return the numerator as a string

string UnlimitedRational::get_q_str(){
    string s=q->to_string();
    return s;
} // Return the denominator as a string
    
string UnlimitedRational::get_frac_str(){
    string s1=p->to_string();
    s1+='/';
    string s2=q->to_string();
    s1+=s2;
    return s1;
} // Return the rational as "p/q"

// Rational arithmetic operations
UnlimitedRational* UnlimitedRational::add(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt*p1=i1->get_p();
    UnlimitedInt*q1=i1->get_q();
    UnlimitedInt*p2=i2->get_p();
    UnlimitedInt*q2=i2->get_q();
    if(q1->get_sign()==0 || q2->get_sign()==0){
        UnlimitedRational* returningit=new UnlimitedRational();
        return returningit;
    }
    UnlimitedInt* a=p1->mul(p1,q2);
    UnlimitedInt* b=p1->mul(p2,q1);
    UnlimitedInt* c=p1->mul(q1,q2);
    UnlimitedInt* d=p1->add(a,b);
    UnlimitedRational* returningit=new UnlimitedRational(d,c);
    delete a;
    delete b;
    return returningit;
}

UnlimitedRational* UnlimitedRational::sub(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt*p1=i1->get_p();
    UnlimitedInt*q1=i1->get_q();
    UnlimitedInt*p2=i2->get_p();
    UnlimitedInt*q2=i2->get_q();
    if(q1->get_sign()==0 || q2->get_sign()==0){
        UnlimitedRational* returningit=new UnlimitedRational();
        return returningit;
    }
    UnlimitedInt* a=p1->mul(p1,q2);
    UnlimitedInt* b=p1->mul(p2,q1);
    UnlimitedInt* c=p1->mul(q1,q2);
    UnlimitedInt* d=p1->sub(a,b);
    UnlimitedRational* returningit=new UnlimitedRational(d,c);
    delete a;
    delete b;
    return returningit;
}
UnlimitedRational* UnlimitedRational::mul(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt*p1=i1->get_p();
    UnlimitedInt*q1=i1->get_q();
    UnlimitedInt*p2=i2->get_p();
    UnlimitedInt*q2=i2->get_q();
    if(q1->get_sign()==0 || q2->get_sign()==0){
        UnlimitedRational* returningit=new UnlimitedRational();
        return returningit;
    }
    UnlimitedInt* a=p1->mul(p1,p2);
    UnlimitedInt* b=p1->mul(q1,q2);
    UnlimitedRational* returningit=new UnlimitedRational(a,b);
    return returningit;
}
UnlimitedRational* UnlimitedRational::div(UnlimitedRational* i1, UnlimitedRational* i2){
    UnlimitedInt*p1=i1->get_p();
    UnlimitedInt*q1=i1->get_q();
    UnlimitedInt*p2=i2->get_p();
    UnlimitedInt*q2=i2->get_q();
    if(q1->get_sign()==0 || q2->get_sign()==0){
        UnlimitedRational* returningit=new UnlimitedRational();
        return returningit;
    }
    UnlimitedInt* a=p1->mul(p1,q2);
    UnlimitedInt* b=p1->mul(q1,p2);
    UnlimitedRational* returningit=new UnlimitedRational(a,b);
    return returningit;
}
