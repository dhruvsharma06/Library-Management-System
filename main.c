#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Define the Book structure
struct Book {
char title[100];
char author[100];
char isbn[14];
};
// Define a linked list node for Book
struct ListNode {
struct Book book;
struct ListNode* next;
};
// Define a hash table for Book
struct HashTable {
struct ListNode* table[100]; // Hash table size
};
// Initialize a new Book
struct Book createBook(char title[100], char author[100], char isbn[14]) {
struct Book newBook;
strcpy(newBook.title, title);
strcpy(newBook.author, author);
strcpy(newBook.isbn, isbn);
return newBook;
}
// Initialize a linked list node
struct ListNode* createListNode(struct Book book) {
struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
newNode->book = book;
newNode->next = NULL;
return newNode;
}
// Initialize a new hash table
struct HashTable* createHashTable() {
struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
for (int i = 0; i < 100; i++) {
hashTable->table[i] = NULL;
}
return hashTable;
}
// Hash function
int hash(char title[100]) {
int hashValue = 0;
for (int i = 0; title[i] != '\0'; i++) {
hashValue += title[i];
}
return hashValue % 100;
}
// Add a book to the hash table
void addBookToHashTable(struct HashTable* hashTable, struct Book book) {
int index = hash(book.title);
struct ListNode* newNode = createListNode(book);
newNode->next = hashTable->table[index];
hashTable->table[index] = newNode;
}
// Search for a book by title in the hash table
struct Book* searchBookByTitleInHashTable(struct HashTable* hashTable, char
title[100]) {
int index = hash(title);
struct ListNode* current = hashTable->table[index];
while (current != NULL) {
if (strcmp(current->book.title, title) == 0) {
return &current->book;
}
current = current->next;
}
return NULL;
}
void arrayLibraryManagement() {
// Array-based library management
struct Book library[100];
int bookCount = 0;
while (1) {
printf("Library Management System (Array):\n");
printf("1. Add Book\n2. List Books\n3. Search Book by Title\n4. Exit\n");
int choice;
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: {
struct Book newBook;
printf("Enter Book Title: ");
scanf(" %[^\n]s", newBook.title);
printf("Enter Author: ");
scanf(" %[^\n]s", newBook.author);
printf("Enter ISBN: ");
scanf(" %[^\n]s", newBook.isbn);
if (bookCount < 100) {
library[bookCount] = newBook;
bookCount++;
printf("Book added successfully.\n");
} else {
printf("The library is full. Cannot add more books.\n");
}
break;
}
case 2:
if (bookCount > 0) {
printf("List of Books in the Library:\n");
for (int i = 0; i < bookCount; i++) {
printf("Title: %s\nAuthor: %s\nISBN: %s\n\n", library[i].title,
library[i].author, library[i].isbn);
}
} else {
printf("The library is empty. No books to list.\n");
}
break;
case 3: {
char searchTitle[100];
printf("Enter the title to search: ");
scanf(" %[^\n]s", searchTitle);
int found = 0;
for (int i = 0; i < bookCount; i++) {
if (strcmp(library[i].title, searchTitle) == 0) {
printf("Book found:\nTitle: %s\nAuthor: %s\nISBN: %s\n", library[i].title,
library[i].author, library[i].isbn);
found = 1;
break;
}
}
if (!found) {
printf("Book not found in the library.\n");
}
break;
}
case 4:
printf("Exiting the Library Management System. Goodbye!\n");
return;
default:
printf("Invalid choice. Please select a valid option.\n");
}
}
}
void linkedListLibraryManagement() {
// Linked list-based library management
struct ListNode* library = NULL;
while (1) {
printf("Library Management System (Linked List):\n");
printf("1. Add Book\n2. List Books\n3. Search Book by Title\n4. Exit\n");
int choice;
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: {
struct Book newBook;
printf("Enter Book Title: ");
scanf(" %[^\n]s", newBook.title);
printf("Enter Author: ");
scanf(" %[^\n]s", newBook.author);
printf("Enter ISBN: ");
scanf(" %[^\n]s", newBook.isbn);
struct ListNode* newNode = createListNode(newBook);
newNode->next = library;
library = newNode;
printf("Book added successfully.\n");
break;
}
case 2:
if (library != NULL) {
printf("List of Books in the Library:\n");
struct ListNode* current = library;
while (current != NULL) {
printf("Title: %s\nAuthor: %s\nISBN: %s\n\n", current->book.title,
current->book.author, current->book.isbn);
current = current->next;
}
} else {
printf("The library is empty. No books to list.\n");
}
break;
case 3: {
char searchTitle[100];
printf("Enter the title to search: ");
scanf(" %[^\n]s", searchTitle);
int found = 0;
struct ListNode* current = library;
while (current != NULL) {
if (strcmp(current->book.title, searchTitle) == 0) {
printf("Book found:\nTitle: %s\nAuthor: %s\nISBN: %s\n", current-
>book.title, current->book.author, current->book.isbn);
found = 1;
break;
}
current = current->next;
}
if (!found) {
printf("Book not found in the library.\n");
}
break;
}
case 4:
printf("Exiting the Library Management System (Linked List). Goodbye!\n");
return;
default:
printf("Invalid choice. Please select a valid option.\n");
}
}
}
void hashTableLibraryManagement() {
// Hash table-based library management
struct HashTable* library = createHashTable();
while (1) {
printf("Library Management System (Hash Table):\n");
printf("1. Add Book\n2. List Books\n3. Search Book by Title\n4. Exit\n");
int choice;
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: {
struct Book newBook;
printf("Enter Book Title: ");
scanf(" %[^\n]s", newBook.title);
printf("Enter Author: ");
scanf(" %[^\n]s", newBook.author);
printf("Enter ISBN: ");
scanf(" %[^\n]s", newBook.isbn);
addBookToHashTable(library, newBook);
printf("Book added successfully.\n");
break;
}
case 2: {
int isEmpty = 1;
for (int i = 0; i < 100; i++) {
struct ListNode* current = library->table[i];
while (current != NULL) {
printf("Title: %s\nAuthor: %s\nISBN: %s\n\n", current->book.title,
current->book.author, current->book.isbn);
current = current->next;
isEmpty = 0;
}
}
if (isEmpty) {
printf("The library is empty. No books to list.\n");
}
break;
}
case 3: {
char searchTitle[100];
printf("Enter the title to search: ");
scanf(" %[^\n]s", searchTitle);
struct Book* foundBook = searchBookByTitleInHashTable(library,
searchTitle);
if (foundBook != NULL) {
printf("Book found:\nTitle: %s\nAuthor: %s\nISBN: %s\n", foundBook-
>title, foundBook->author, foundBook->isbn);
} else {
printf("Book not found in the library.\n");
}
break;
}
case 4:
printf("Exiting the Library Management System (Hash Table). Goodbye!\n");
return;
default:
printf("Invalid choice. Please select a valid option.\n");
}
}
}
int main() {
int choice;
printf("Library Management System\n");
printf("Select Data Structure:\n");
printf("1. Array\n2. Linked List\n3. Hash Table\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: // Array
arrayLibraryManagement();
break;
case 2: // Linked List
linkedListLibraryManagement();
break;
case 3: // Hash Table
hashTableLibraryManagement();
break;
default:
printf("Invalid choice. Exiting the Library Management System.\n");
break;
}
return 0;
}