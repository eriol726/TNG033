#include "set.h"

//Default constructor
Set::Set ()
{
   head = new Node(0,nullptr);
}

//Constructor creating a set
//from n integers in a non-sorted array a
Set::Set (int a[], int n)
{

    head = new Node(0,nullptr);


    for(int k = 0; k < n; k++)
    {
            Node *temp = head;

            while(temp->next && (temp->next->value <= a[k]))
            {
                temp = temp->next;
            }
            if(temp->value != a[k]){
                Node *newNode = new Node(a[k], temp->next);
                temp->next  = newNode;
            }
    }

}

//copy constructor
Set::Set (const Set &source)
{

    head = new Node(0, nullptr);
    Node *source_temp = source.head;
    Node *temp = head;




    while(source_temp->next)
    {

        temp->next = new Node(source_temp->next->value, nullptr);

        temp  = temp->next;
        source_temp = source_temp->next;

    }


}

//Destructor: deallocate all nodes
Set::~Set ()
{
    delete [] head; //deallocate the table
}

//Test if set is empty
bool Set::empty () const
{
    if(!head->next)
    {
        return false;
    }
    return true;
}

//Return number of elements in the set
int Set::cardinality() const
{
    int n = 0;
    Node *temp = head;
    while(temp->next)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

//Test if x is an element of the set
bool Set::member (int x) const
{

    Node *temp = head;
    while(temp->next)
    {
        if(temp->value == x){
            return true;
        }
        temp = temp->next;
    }
    return false;
}


bool Set:: operator<=(const Set& b) const
{
    Node *node_b = b.head;
    Node *node_this = head;

    //loop som jämför alla element i node_b med element nr n i node_this (sekvensiellt)
    while(node_this->next){
        if(!b.member(node_this->value)){
            return false;
        }

        node_this = node_this->next;
    }
    return true;


}


bool Set:: operator==(const Set& b) const
{

    Set newSet;
    Node *node_b = b.head;
    //Node *node_this = head;

    Node *newNode = newSet.head;

    //använder mig av föregående oppertor, Delmängderan måste finnas i varadra för att det ska bli true
    if (b <= *this && *this <= b){
        return true;
    }
    else{
        return false;
    }
}


bool Set:: operator<(const Set& b)  const
{


    Node *temp_b = b.head;
    Node *temp_one = head;

    if (*this <= b && !(b <= *this) ){
        return true;
    }
    else{
        return false;
    }

}


//Set union
//Repeated values are not allowed
Set Set::operator+ (const Set& b) const
{


    //skapar en ny lista som är helt tom
    Set newSet;

    Node *temp_b = b.head;
    Node *temp_one = head;
    Node *temp_newSet = newSet.head;


    while(temp_b->next && temp_one->next)
    {
        //lägger till i listan om villkor gäller
        if (temp_b->next->value < temp_one->next->value){
            temp_newSet->next = new Node(temp_b->next->value, nullptr);
            temp_b = temp_b->next;
        }
        //lägger till i listan om villkor gäller
        else if(temp_b->next->value > temp_one->next->value){
            temp_newSet->next = new Node(temp_one->next->value, nullptr);
            temp_one = temp_one->next;
        }
        //lägger till i valfritt värde eftersom dom ha varit lika
        //stegar frammåt i båda listor
        else
        {
            temp_newSet->next = new Node(temp_one->next->value, nullptr);
            temp_one = temp_one->next;
            temp_b = temp_b->next;

        }
        //denne ska alltid peka vidare
        temp_newSet = temp_newSet->next;

    }

    //kommando för att lägga till sista värdet
    if(temp_one->next){
        temp_newSet->next = new Node(temp_one->next->value, nullptr);
    }
    else{
         temp_newSet->next = new Node(temp_b->next->value, nullptr);
    }

    return newSet;
}

//Set intersection Alla siffror som e lika ska in i listan
Set Set::operator* (const Set& b) const
{
    //Add code
    Set newSet;

    Node *node_b = b.head;
    Node *node_this = head;
    //tildelar min nya lista med en tom nod
    Node *newNode = newSet.head;

    //loop som jämför alla element i node_b med element nr n i node_this
    while(node_this->next){
        while(node_b->next){
                //om siffrorna e lika, lägg till i listan
            if (node_b->next->value == node_this->next->value){
                newNode->next = new Node(node_b->next->value, nullptr);
                newNode = newNode->next;
            }

            node_b = node_b->next;
        }
        node_b = b.head;
        node_this = node_this->next;
    }

    return newSet;
}

//Set difference, de element som inte finns i lisa S1 ska läggas i nya listan
Set Set::operator- (const Set& b) const
{
    bool loop = false;
    Set newSet;

    Node *node_b = b.head;
    Node *node_this = head;
    Node *newNode = newSet.head;
    int i = 1;
    while(node_this->next){

        while(node_b->next){
                //om siffrorna e olika, lägg till i listan, men endas en siffra

            if (node_b->next->value != node_this->next->value ){

                i++;
                loop = true;
            }
            else{
                //om det ngn gång påträffas en siffra som e samma, är chansen rökt
                //denna nod hoppas över plus att loopen blir falsk så att vi aldrig kommer in i nästa sats
                loop = false;
                node_b = node_b->next;
            }
            //lägger till om siffran var lika och cykeln e slut
            if(loop && node_b->next->next == nullptr){
                newNode->next = new Node(node_this->next->value, nullptr);
                newNode = newNode->next;
            }

            node_b = node_b->next;
        }
        loop = false;
        i = 0;
        node_b = b.head;
        node_this = node_this->next;
    }


    return newSet;
}

//set union with set {x}
Set Set::operator+(int x) const
{
    Set newSet;

    Node *node_this = head;
    Node *newNode = newSet.head;

    while(node_this->next){
            //jämför eftersom x ska komma in på rätt position
            if( x > node_this->value  && x  < node_this->next->value ){
                node_this->value = x;
                newNode->next = new Node(x, nullptr);
            }
            else{
                newNode->next = new Node(node_this->next->value, nullptr);
                node_this = node_this->next;
            }
            //newNode pekas vidare
            newNode = newNode->next;

    }

    return newSet;
}

//set difference with set {x}
Set Set::operator-(int x) const
{
    Set newSet;
    Node *node_this = head;
    Node *newNode = newSet.head;

    while(node_this->next){

            if( node_this->next->value  == x ){
                //stega bara vidare om siffran e lika, lägg alltså inte till någonting
                node_this = node_this->next;
            }
            else{
                newNode->next = new Node(node_this->next->value, nullptr);
                node_this = node_this->next;
                newNode = newNode->next;
            }

    }

    return newSet;

}



//Assignment operator
const Set& Set::operator=(const Set &s)
{
    while(head->next)
    {
        Node *newNode = head->next;
        head->next = newNode->next;
        delete newNode;
    }

    Node *temp_s = s.head;
    Node *temp_c = head;

    while(temp_s->next){

        temp_c->next =new Node(temp_s->next->value, nullptr);
        temp_c = temp_c->next;
        temp_s = temp_s->next;
    }

    return (*this);
}


ostream& operator<< (ostream& os, const Set& theSet)
{

   if (!theSet.head)
        cout << "List is empty!!" << endl;
    else
    {
        os << "{ ";
        for(Node *p = theSet.head; p; p = p->next)
            if(p->value > 0){
                os << p->value << " ";

        }
        else if(!theSet.empty()){
            os << "list is empty ";
        }
        os << "}"<< endl;
    }

    return os;
}

