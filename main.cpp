#include<iostream>
#include<math.h>
using namespace std;;

class Node
{
    public:
    int coeff;
    int exp;
    Node *next;

};


class Polynomial
{
    private:
    Node *poly;
    public:
    Polynomial(int n)
    {
        poly = NULL;
        Node *last,*t;
        cout<<"ENTER EACH TERM WITH COEFFICENT AND EXPONENT"<<endl;
        for(int i=0;i<n;i++)
        {
            t = new Node;
            cin>>t->coeff>>t->exp;
            t->next = NULL;
           
            if(poly==NULL)
            {
                
                poly = last= t;
            }
            else
            {
                last->next= t;
                last = t;
            }
            

        }
    }
    void display()
    {
        Node *p = poly;
        while (p)
        {
            cout<<p->coeff<<"x^"<<p->exp;
            p = p->next;
            if(p)
            cout<<"+";
        }
        cout<<endl;
    }
    double eval(int x)
    {
        double sum=0;
        Node *p = poly;
        while(p)
        {
            sum+=p->coeff * pow(x,p->exp);
            p = p->next; 
        }
        return sum;
    }
    

    void sum(Polynomial p)
    {
       Node * p1 = poly;
        Node *p2 = p.poly;
        Node *sum = NULL;
        Node *t = NULL;
        Node *last = NULL;
       while(p1!=NULL&&p2!=NULL)
       {
           t = new Node;
           t->next = NULL;
           if(p1->exp > p2->exp)
           {
               t->coeff = p1->coeff;
               t->exp = p1->exp;
               p1 = p1->next;
           }
           else if(p1->exp < p2->exp)
           {
               t->coeff = p2->coeff;
               t->exp = p2->exp;
               p2 = p2->next;
           }
           else
           {
               t->coeff = p1->coeff;
               t->exp = p1->exp + p2->exp;
               p1 = p1->next;
               p2 = p2->next;
           }
           if(sum==NULL)
           { 
               sum=last=t;
           }
           else
           {
               last->next = t;
               last = t;
           }
           
       }
       while (p1)
       {
                t = new Node;
                t->next = NULL;
               t->coeff = p1->coeff;
               t->exp = p1->exp;
               p1 = p1->next;
               last->next=t;
               last = t;
       }
       while (p2)
       {
        t = new Node;
         t->next = NULL;
         t->coeff = p2->coeff;
         t->exp = p2->exp;
        p2 = p2->next;
        last->next=t;
        last = t;
       }
       poly = sum;       
    }
    
};

int main()
{
    Polynomial p1(4);
    Polynomial p2(4);
    p1.sum(p2);
    p1.display();
    return 0;
}