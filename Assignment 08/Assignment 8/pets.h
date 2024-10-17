using namespace std;

class IntNode;      // forward declaration

typedef IntNode* IntNodePtr;

class IntNode
{
    private:
        string name;
        string type;
        int age;
        IntNodePtr link;

    public:
        IntNode(string name, string type, int age, IntNodePtr theLink);
        void setName(string name);
        void setType(string type);
        void setAge(int age);
        void setLink(IntNodePtr theLink);
        string getName() const;
        string getType() const;
        int getAge() const;
        IntNodePtr getLink() const;
};


void insert(IntNodePtr afterMe, string name, string type, int age);
void headInsert(IntNodePtr &head);
void display(IntNodePtr head);
void tailInsert(IntNodePtr &head);
void deleteNodeByName(IntNodePtr &head);
int countNodes(IntNodePtr head);
void searchGivenType(IntNodePtr head);
void averageAgeIterative(IntNodePtr head);
void averageAgeRecursive(IntNodePtr head);
int displayMenu();

