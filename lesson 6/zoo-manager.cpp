#include <iostream>
#include <time.h>
#include <stdlib.h>

#define MAX_COUNT_ANIMAL 100    //maximum count animal in zoo
#define INDEX_HEALTH 100        //maximum index health

using namespace std;

//constants for the user menu
const int MENU_ONE = 1;
const int MENU_TWO = 2;
const int MENU_THREE = 3;
const int MENU_FOUR = 4;
const int MENU_FIVE = 5;
const int MENU_SIX = 6;

class Animal{
    private:
            string m_kindAnimal; //kind animal
            string m_nameAnimal; //nickname animal
            int m_ageAnimal; //age
            int m_numPaws; //number of paws
            int m_indexHealth; //health indicator
            bool m_isShow;//animal in the cage or at an exhibition
    public:
            Animal();
            Animal(string kind, string name, int age, int paws, int indexHealth, bool isShow);
            void setKind(string kind){
                m_kindAnimal = kind;
            }
            string getKind (){
                return m_kindAnimal;
            }
            void setName(string name){
                m_nameAnimal = name;
            }
            string getName (){
                return m_nameAnimal;
            }
            void setAgeAnimal(int age){
                m_ageAnimal = age;
            }
            int getAgeAnimal(){
                return m_ageAnimal;
            }
            void setNumPaws(int paws){
                m_numPaws = paws;
            }
            int getNumPaws(){
                return m_numPaws;
            }
            void setIndexHealth (int indexHealth){
                m_indexHealth = indexHealth;
            }
            int getIndexHealth(){
                return m_indexHealth;
            }
            void setIsShow(bool isShow){
                m_isShow = isShow;
            }
            int getIsShow(){
                return m_isShow;
            }
            ~Animal(){
            }
};

Animal::Animal(){
    m_kindAnimal = "no kind";
    m_nameAnimal = "no name";
    m_ageAnimal = 0;
    m_indexHealth = 0;
    m_numPaws = 0;
    m_isShow = true;
}
Animal::Animal(string kind, string name, int age, int indexHealth, int paws, bool isShow){
    m_kindAnimal = kind;
    m_nameAnimal = name;
    m_ageAnimal = age;
    m_indexHealth = indexHealth;
    m_numPaws = paws;
    m_isShow = isShow;
}

class Manager{
    private:
        Animal zoo[MAX_COUNT_ANIMAL];
        int m_size;
    public:
        Manager(){
            m_size = 0;
        }
        void addAnimal();
        void editAnimal(string kind);
        void showAnimal();
        void deleteAnimal(string kind);
        void showPopulation(string kind);
        void chooseMenu();
};

void Manager::addAnimal(){
    string kind;
    string name;
    int age;
    int paws;
    int indexHealth;
    bool isShow;

    if (m_size >= MAX_COUNT_ANIMAL){
        cout<<"No space left!"<<endl;
        return;
    }
    cout<<"Input kind animal: ";
    cin>>kind;
    cout<<"Name: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    srand(time(NULL));
    indexHealth = rand()%INDEX_HEALTH;
    cout<<"Paws: ";
    cin>>paws;
    cout<<"Animal in a cage(1)/aviary(0): ";
    cin>>isShow;
    Animal p(kind,name,age,indexHealth,paws,isShow);
    zoo[m_size] = p;
    m_size++;
}

void Manager::editAnimal(string kind){
    string kindAnimal;
    string name;
    int age;
    int health;
    int pawsNum;
    bool isShow;

    for (int i = 0 ; i < m_size ; i++){
        if (zoo[i].getKind().compare(kind) == 0){
            cout<<"NEW Kind animal: ";
            cin>>kindAnimal;
            zoo[i].setKind(kindAnimal);
            cout<<"NEW Name: ";
            cin>>name;
            zoo[i].setName(name);
            cout<<"NEW Age: ";
            cin >> age;
            zoo[i].setAgeAnimal(age);
            srand(time(NULL));
            health = rand()%INDEX_HEALTH;
            zoo[i].setIndexHealth(health);
            cout<<"NEW Paws: ";
            cin >> pawsNum;
            zoo[i].setNumPaws(pawsNum);
            cout<<"Animal in a cage(1)/aviary(0): ";
            cin >>isShow;
            zoo[i].getIsShow();
            cout<<"......edit complite"<<endl;
            } else {
                    cout << "Kind not found!!!"<<endl;
                    }
     }
 }

void Manager::deleteAnimal(string kind){
    for (int i = 0 ; i < m_size ; i++){
        if (zoo[i].getKind().compare(kind) == 0){
            delete zoo[i];
            zoo[i] = nullptr;
            cout<<"-=Animal deleted=-";
        } else {
                cout << "Kind not found!!!";
                }
    }
}

void Manager::showPopulation(string kind){
    for (int i = 0; i < m_size; i++){
        if (zoo[i].getKind().compare(kind) == 0 ){
            cout<<endl<<"==============Show choose kind animal:===================="<<endl;
            cout<<"Kind:\tName:\tAge:\tHealth:\tPaws:\tCage(1)/Aviary(0)"<<endl;
            cout<<"=========================================================="<<endl;
            cout<<zoo[i].getKind()<<"\t"<<zoo[i].getName()<<"\t"<<zoo[i].getAgeAnimal()<<"\t"<<zoo[i].getIndexHealth()<<"\t"<<zoo[i].getNumPaws()<<"\t\t"<<zoo[i].getIsShow()<<endl;
            cout<<"=========================================================="<<endl;
        }   else {
                cout << "Kind not found!!!";
            }
    }
}

void Manager::showAnimal(){
    cout<<endl<<"=====================About animal:========================"<<endl;
    cout<<"Kind:\tName:\tAge:\tHealth:\tPaws:\tCage(1)/Aviary(0)"<<endl;
    cout<<"=========================================================="<<endl;
    for (int i = 0; i < m_size; i++){
        cout<<zoo[i].getKind()<<"\t"<<zoo[i].getName()<<"\t"<<zoo[i].getAgeAnimal()<<"\t"<<zoo[i].getIndexHealth()<<"\t"<<zoo[i].getNumPaws()<<"\t\t"<<zoo[i].getIsShow()<<endl;
    }
    cout<<"=========================================================="<<endl;
}

void Manager::chooseMenu(){
    int menu = 0;
    string kind;

    cout<<endl<<"-=Welcome the manager ZOO=-"<<endl<<endl;
    cout<<"Choose menu:"<<endl;
    cout<<"1. Add animal"<<endl;
    cout<<"2. Edit animal"<<endl;
    cout<<"3. Delete animal"<<endl;
    cout<<"4. Show populations"<<endl;
    cout<<"5. Show animal"<<endl;
    cout<<"6. Exit"<<endl;
    cin>>menu;
    switch(menu){
        case MENU_ONE:  cout<<"\t-=Add animal=-"<<endl;
                        addAnimal();
                        break;
        case MENU_TWO:  cout<<"Enter the kind of animal for editing: ";
                        cin>>kind;
                        editAnimal(kind);
                        break;
        case MENU_THREE:cout<<"Delete animal. Input kind animal: ";
                        cin>>kind;
                        deleteAnimal(kind);
                        break;
        case MENU_FOUR: cout<<"What kind of animal are we going to look at?  ";
                        cin>>kind;
                        showPopulation(kind);
                        break;
        case MENU_FIVE: showAnimal();
                        break;
        case MENU_SIX:  cout<<"Exit. Good bye."<<endl;
                        exit(0);
        default:        cout<<"\t!!!Wrong choose!!! !!TRY Again!!!"<<endl;
                        break;
    }
}

int main()
{
    Manager man;

    for(;;){
        man.chooseMenu();
    }
    return 0;
}
