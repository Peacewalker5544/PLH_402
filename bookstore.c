#include "kappalib.h"



#define SELF struct Address *self
typedef struct Address {
char* street;
int number;
char* city;
void (*printAddress) (SELF);
void (*setAddress) (SELF ,char* s, int n, char* c);
}Address;

void setAddress(SELF ,char* s, int n, char* c){
self->street = s;
self->number = n;
self->city = c;
};

void printAddress(SELF){
write("Address: %s %d, %s\n", self->street, self->number, self->city);
};

Address ctor_Address = {.printAddress = printAddress,.setAddress = setAddress};
#undef SELF

#define SELF struct Person *self
typedef struct Person {
char* firstName, lastName;
char* email;
int phone;
Address address;
void (*printPersonInfo) (SELF);
void (*setPerson) (SELF ,char* fn, char* ln, char* email, int phone, Address addr);
}Person;

void setPerson(SELF ,char* fn, char* ln, char* email, int phone, Address addr){
self->firstName = fn;
self->lastName = ln;
self->email = email;
self->phone = phone;
self->address = addr;
};

void printPersonInfo(SELF){
write("%s %s, email: %s phone: %d\n", self->firstName, self->lastName, self->email, self->phone);
self->address.printAddress(&self->address);
};

Person ctor_Person = {.printPersonInfo = printPersonInfo,.setPerson = setPerson,};
#undef SELF

#define SELF struct Book *self
typedef struct Book {
char* title, isbn;
Person author;
int numOfCopies;
double price;
void (*printBook) (SELF);
void (*setBook) (SELF ,char* t, Person a, int numOfCopies, double price);
}Book;

void setBook(SELF ,char* t, Person a, int numOfCopies, double price){
self->title = t;
self->author = a;
self->numOfCopies = numOfCopies;
self->price = price;
};

void printBook(SELF){
write("Title: %s\n", self->title);
writeStr("Author:");
self->author.printPersonInfo(&self->author);
write("Price:%f\n", self->price);
write("Number of available copies: %d\n", self->numOfCopies);
};

Book ctor_Book = {.printBook = printBook,.setBook = setBook,};
#undef SELF

#define SELF struct Order *self
typedef struct Order {
int orderNum;
Book book;
int quantity;
Address shippingAddress;
int delivered;
void (*printOrder) (SELF);
void (*setOrder) (SELF ,int orNum, Book b, int q, Address sh, int del);
}Order;

void setOrder(SELF ,int orNum, Book b, int q, Address sh, int del){
self->orderNum = orNum;
self->book = b;
self->quantity = q;
self->shippingAddress = sh;
self->delivered = del;
};

void printOrder(SELF){
};

Order ctor_Order = {.printOrder = printOrder,.setOrder = setOrder,};
#undef SELF

#define SELF struct Bookstore *self
typedef struct Bookstore {
char* name;
Book listOfBooks[100];
int numOfBooks;
Order listOfOrders[100];
int numOfOrders;
double (*calculateTotalOrdersIncome) (SELF);
void (*printBookStoreBooks) (SELF);
void (*addBook) (SELF ,Book b);
void (*putOrder) (SELF ,Order o);
}Bookstore;

void putOrder(SELF ,Order o){
self->listOfOrders[self->numOfOrders] = o;
self->numOfOrders += 1;
};

void addBook(SELF ,Book b){
self->listOfBooks[self->numOfBooks] = b;
self->numOfBooks += 1;
};

void printBookStoreBooks(SELF){
for (int i = 0 ; i < self->numOfBooks ; i += 1){
self->listOfBooks[i].printBook(&self->listOfBooks[i]);;}
};

double calculateTotalOrdersIncome(SELF){
double total;
total = 0;
for (int i = 0 ; i < self->numOfOrders ; i += 1){
if (self->listOfOrders[i].self->delivered){
total = total + self->listOfOrders[i].self->quantity * self->listOfOrders[i].self->book.self->price;};;}
return total;
};

Bookstore ctor_Bookstore = {.calculateTotalOrdersIncome = calculateTotalOrdersIncome,.printBookStoreBooks = printBookStoreBooks,.addBook = addBook,.putOrder = putOrder,};
#undef SELF

int orderId;

Address createAddress(char* s, int n, char* c){
Address a = Address;
a.setAddress(&as, n, c);
return a;
}

Person createPerson(char* fn, char* ln, char* email, int phone, Address addr){
Person p = Person;
p.setPerson(&pfn, ln, email, phone, addr);
return p;
}

Book createBook(char* t, Person a, int numOfCopies, double price){
Book b = Book;
b.setBook(&bt, a, numOfCopies, price);
return b;
}

Order createOrder(int orNum, Book b, int q, Address sh, int del){
Order ord = Order;
ord.setOrder(&ordorNum, b, q, sh, del);
return ord;
}

Bookstore createBookstore(char* n){
Bookstore bs = Bookstore;
bs.self->name = n;
bs.self->numOfBooks = 0;
bs.self->numOfOrders = 0;
return bs;
}

void main() {
orderId = 0;
Address a, a1 = Address;
a = createAddress("Stadiou", 10, "Stadiou");
Person author = Person;
author = createPerson("Christos", "Papadimitriou", "cpap@gmail.com", 12345, a);
Book b = Book;
b = createBook("Computation Theory", author, 34.3, 100);
Bookstore bs = Bookstore;
bs = createBookstore("Papasotiriou");
bs.addBook(&bs,b);
a = createAddress("Wall Street", 10, "NY");
author = createPerson("Dennis", "Richie", "richie@gmail.com", 54321, a);
b = createBook("C Programming", author, 10.3, 100);
bs.addBook(&bs,b);
bs.printBookStoreBooks(&bs);
Order ord = Order;
ord = createOrder(orderId, b, 2, a, 0);
orderId += 1;
bs.putOrder(&bs,ord);
write("Bookstore orders income: %.2f\n", bs.calculateTotalOrdersIncome(&bs));
}
