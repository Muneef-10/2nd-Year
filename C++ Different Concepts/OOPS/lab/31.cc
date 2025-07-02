#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Member {
    int MemberID;
    string MemberName;
    string MemberType;

public:
    Member(int id, string name, string type)
        : MemberID(id), MemberName(name), MemberType(type) {}

    int getMemberID() { return MemberID; }
    string getMemberName() { return MemberName; }
    string getMemberType() { return MemberType; }
};

class Book {
    int BookID;
    string Title;
    string Publisher;

protected:
    string Author;
    int Edition;

public:
    Book(int bookID, string title, string publisher, string author, int edition)
        : BookID(bookID), Title(title), Publisher(publisher), Author(author), Edition(edition) {}

    int getBookID() { return BookID; }
    string getTitle() { return Title; }
    string getPublisher() { return Publisher; }
};

class Journal : public Book {
    string Editor;
    int Volume;
    int Issue;

public:
    Journal(int bookID, string title, string publisher, string editor, int volume, int issue)
        : Book(bookID, title, publisher, "", 0), Editor(editor), Volume(volume), Issue(issue) {}

    string getEditor() { return Editor; }
    int getVolume() { return Volume; }
    int getIssue() { return Issue; }
};

class LibraryDb {
    static vector<Member> Members;
    static vector<int> BooksTaken;
    static vector<Book*> Books;
    static vector<bool> BookStatus;

public:
    static void addMember(Member member) {
        Members.push_back(member);
        BooksTaken.push_back(0);
    }

    static void addBook(Book* book) {
        Books.push_back(book);
        BookStatus.push_back(true);
    }

    static bool ValidateMemberEligibility(int MemberID) {
        for (size_t i = 0; i < Members.size(); i++) {
            if (Members[i].getMemberID() == MemberID && BooksTaken[i] < 5) {
                return true;
            }
        }
        return false;
    }

    static bool ValidateBookAvailability(int BookID) {
        for (size_t i = 0; i < Books.size(); i++) {
            if (Books[i]->getBookID() == BookID && BookStatus[i]) {
                return true;
            }
        }
        return false;
    }

    static void IssueBook(int MemberID, int BookID) {
        for (size_t i = 0; i < Members.size(); i++) {
            if (Members[i].getMemberID() == MemberID) {
                for (size_t j = 0; j < Books.size(); j++) {
                    if (Books[j]->getBookID() == BookID) {
                        BooksTaken[i]++;
                        BookStatus[j] = false;
                        cout << "Book issued successfully!" << endl;
                        return;
                    }
                }
            }
        }
        cout << "Error issuing book." << endl;
    }
};

vector<Member> LibraryDb::Members;
vector<int> LibraryDb::BooksTaken;
vector<Book*> LibraryDb::Books;
vector<bool> LibraryDb::BookStatus;

class Transaction {
    int Tid;
    Member mObj;
    Book* bObj;

public:
    Transaction(int tid, Member member, Book* book)
        : Tid(tid), mObj(member), bObj(book) {}

    void BorrowBook() {
        if (LibraryDb::ValidateMemberEligibility(mObj.getMemberID()) &&
            LibraryDb::ValidateBookAvailability(bObj->getBookID())) {
            
            time_t now = time(0);
            tm* ltm = localtime(&now);

            cout << "Borrow date: "
                 << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;

            ltm->tm_mday += 14; 
            mktime(ltm);

            cout << "Return date: "
                 << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;

            LibraryDb::IssueBook(mObj.getMemberID(), bObj->getBookID());
        } else {
            cout << "Cannot issue book. Either member is not eligible or book is unavailable." << endl;
        }
    }
};

int main() {
    Member member1(1, "Alice", "Student");
    Member member2(2, "Bob", "Faculty");

    LibraryDb::addMember(member1);
    LibraryDb::addMember(member2);

    Book* book1 = new Book(101, "C++ Programming", "Pearson", "Bjarne Stroustrup", 4);
    Book* book2 = new Book(102, "Data Structures", "McGraw Hill", "Ellis Horowitz", 3);
    Journal* journal1 = new Journal(201, "AI Journal", "Springer", "John Doe", 5, 2);

    LibraryDb::addBook(book1);
    LibraryDb::addBook(book2);
    LibraryDb::addBook(journal1);

    Transaction transaction1(1, member1, book1);
    transaction1.BorrowBook();

    delete book1;
    delete book2;
    delete journal1;

    return 0;
}
