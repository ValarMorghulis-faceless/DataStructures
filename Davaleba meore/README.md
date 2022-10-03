# დავალება II

*დავალება Platypus კლასსზე*

**1. default constructor უპარამეტრო კონსტრუქტორი რომელიც ქმნის მკვდარ იხვნისკარტას**
```cpp
 //დიფოლტ კონსტრუქტორი რომელიც ქმნის მკვდარ იხვნისკარტას
    public :

         Platypus(){
            srand(time(0));
            weight = 0.0;
            age = 0;
            name = "-";
            gender = '-';
            alive = false;
            mutant = false;
         }
```
**2.პარამეტრიანი კონსტრუქტორი რომელსაც გადასცემთ მნიშვნელობებს იმისათვის რომ განსაზღვროთ ობიექტის gender, weight, age, და name ცვლადების მნიშვნელობები, აგრეთვე  default-ად ობიექტი უნდა იყოს alive(ცოცხალი) და not mutant(არა-მუტანტი).**
```cpp
 //კონსტრუქტორი რომელსაც შეგვიძლია მივანიჭოთ მნიშვნელობები float  weight , short age (months) , char name (initial), char gender, bool alive ,bool mutant 
         Platypus(char gender, float weight, short age, string name) {
            srand(time(0));
            this->weight = weight;
            this->age = age;
            this->name = name;
            this->gender = gender;
            alive = true;
            mutant = false;
         }
```
**3.ფუნქცია print რომელიც გამოიტანს იხვნისკარტას შესახებ ინფორმაციას ლამაზი და ადვილად აღსაქმელი ფორმითა და ფორმატით.**
```cpp
//ფუნქცია print რომელიც გამოიტანს იხვნისკარტას შესახებ ინფორმაციას ლამაზი და ადვილად აღსაქმელი ფორმითა და ფორმატით.  :))))
         void print() {
            string gen = (gender == 'm') ? "mamrobiti" : "mdedrobiti";
            printf("\nIxvniskarta %s aris %s %d wlis,\n",name.c_str(),gen.c_str(),age);
            string life = (alive) ? "Tsotskhalia" : "Mkvdaria :(";
            string mutantS = (mutant) ? "mutaciit" : "mutaciis gareshe";
            printf("aris %f kilogrami da %s %s \n",weight,life.c_str(),mutantS.c_str());
         }
```
**4.ფუნქცია age_me რომელიც არაფერს აბრუნებს, მაგრამ ცვლის ობიექტის ასაკს. მასში უნდა იყოს გათვალისწინებული 2% შანსი იმისა რომ ობიექტი შესაძლოა გახდეს მუტანტი. ყოველ-ჯერზე  age_me  ფუნქციის გამოძახებისას ობიექტს აქვს  შანსი რომ მოკვდეს და ეს შანსი ტოლია 10-ჯერ იხვნისკარტის წონისა, ანუ 5 კგ იხვნისკარტას აქვს 50% შანსი რომ მოკვდეს. 10 და მეტ კილოიანი იხნისკარტას სიკვდილის ალბათობა 100%-ია.**
```cpp
void age_me(){
            if (alive == false)
            return ;
            age++;
            _generateMutation();
            _generateDeath();
         }
```
```cpp
// წონა * 10 = n% სიკვდილის შანსს
         void _generateDeath() {
            if (_grade() <= (weight * 10))
            alive = false;
         }
         // 2% შანსი რომ გახდეს მუტანტი
         void _generateMutation() {
            if (_grade() <= 2)
            mutant = true;
         }
```
**5.ფუნქცია  fight- რომელიც პარამეტრად იღებს სხვა პლატიპუსს. რომელიც ახდენს იმ იხვნისკარტას შებრძოლებას რომელზეც ხდება ფუნქციის გამოძახება (calling_platypus ) მეორესთან რომელიც პარამეტრად გადაეცემა (other_platypus). გამარჯვებული ვლინდება ძალების შეფარდებიდან ( "fight ratio") გამომდინარე (calling_platypus წონა /other_platypus წონა) * 50. აიღება შემთხვევითი რიცხვი 1 დან 100-მდე. თუ ძალთა შეფარდება მეტია ამ შემთხვევით რიცხვზე  calling_platypus - იმარჯვებს, თუ არადა გამარჯვებულია მეორე.**
```cpp
 void fight(Platypus * target){
            if(alive == false)
            return ;
            float fightRatio = (weight / target->getWeight()) * 50.0f;

            if (fightRatio > static_cast<float>(_grade()))
                target->die();
            else
                die();
         }
```
**6.ფუნქცია eat ზრდის იხვნისკარტას წონას რამდომად მისი მიმდინარე წონის 0.1% - 5.0% -ით.**
```cpp
   /*
ფუნქცია რომელიც ზრდის იხნვისკარტას წონას შემთხვევითი რაოდენობიტ 0.1%-დან 5.0%-მდე იხვნისკარტას წონის
         */
         void eat(){
            if (alive == false)
            return;
            float weightAmount = (5.0f * _grade()) / 100.0f;
            weightAmount = (weightAmount < 0.1f) ? 0.1f : weightAmount;
            weight += weight *weightAmount;
         }
```
**7.ფუნქცია  hatch(ახალშობილი) რომელიც ანიჭებს ახალდაბადებულ პლატიპუსს შემდეგ პარამეტრებს alive=true, mutant=false, და age=0. სქესი  'm' ან 'f' ერთნაირი ალბათობით. წონა რანდომად 0.1 დან - 1.0 კგ. სახელი მომხმარებელს თავად შეუძლია განუსაზღვროს ან შესაძლებელია სახელი იყოს რაიმე შემთხვევითად განსაზღვრული სიმბოლო (character chosen randomly).**
```cpp
Platypus * hatch(){ printf("**\n");
         if (alive == false)
         return NULL;
         char gender = ' ';
         string name = "";
         if (_grade() > 50) {
            gender = 'f';
            name = nameF[_grade() % nameSize];
         } else {
            gender = 'm';
            name = nameM[_grade() % nameSize];
         }
         float weight = static_cast<float>(_grade()) / 100.0f;
         weight = (weight < 0.1f) ? 0.1f : weight;
         short age = 0;

         return (new Platypus(gender, weight, age, name));
         }

         void die(){
            alive = false;
         }
         float getWeight() const {
            return weight;
         }
```
## კლასის ტესტირებები
```cpp
void eatTest(Platypus * p){
    printf("-----------EAT TEST-------------\n");
    p->print();
    p->eat();
    printf("- - - - - - - - - - - - - - - - \n");
    p->print();
    printf("--------------------------------\n");
}
void ageTest(Platypus * p){
    printf("------------AGE TEST------------\n");
    p->print();
    p->age_me();
    printf("- - - - - - - - - - - - - - - - \n");
    p->print();
    printf("--------------------------------\n");
}

void fightTest(Platypus * p1, Platypus * p2){
    printf("-----------FIGHT TEST-----------\n");
    p1->print();
    p2->print();
    p1->fight(p2);
    printf("- - - - - - - - - - - - - - - - \n");
    p1->print();
    p2->print();
    printf("--------------------------------\n");
}
```
## int main ფუნქცია და ტესტების გამოძახება (საბოლოო შედეგი)
```cpp
// int main ფუნქცია
int main (int argc, char *argv[])
{
   

// vtestavt funqciebs da klasebs
   Platypus * root = new Platypus('f', 0.3f, 1, "Ixvi");
   ageTest(root);
   Platypus * childA = root->hatch();
   eatTest(childA);
   Platypus * childB = root->hatch();
   eatTest(childB);

   fightTest(childA, childB);


// vshlit minichebul monacemebs rata ar moxdes stackoverflow

    delete root;
    delete childA;
    delete childB;
    return 0;
}
```
# _____________________________________
### კომპილერის შედეგი კოდის გაშვების შემდეგ
```
------------AGE TEST------------

Ixvniskarta Ixvi aris mdedrobiti 1 wlis,
aris 0.300000 kilogrami da Tsotskhalia mutaciis gareshe 
- - - - - - - - - - - - - - - - 

Ixvniskarta Ixvi aris mdedrobiti 2 wlis,
aris 0.300000 kilogrami da Tsotskhalia mutaciis gareshe 
--------------------------------
**
-----------EAT TEST-------------

Ixvniskarta Ikhvi1 aris mamrobiti 0 wlis,
aris 0.820000 kilogrami da Tsotskhalia mutaciis gareshe 
- - - - - - - - - - - - - - - - 

Ixvniskarta Ikhvi1 aris mamrobiti 0 wlis,
aris 3.936000 kilogrami da Tsotskhalia mutaciis gareshe 
--------------------------------
**
-----------EAT TEST-------------

Ixvniskarta Ikhvi4 aris mamrobiti 0 wlis,
aris 0.480000 kilogrami da Tsotskhalia mutaciis gareshe 
- - - - - - - - - - - - - - - - 

Ixvniskarta Ikhvi4 aris mamrobiti 0 wlis,
aris 2.304000 kilogrami da Tsotskhalia mutaciis gareshe 
--------------------------------
-----------FIGHT TEST-----------

Ixvniskarta Ikhvi1 aris mamrobiti 0 wlis,
aris 3.936000 kilogrami da Tsotskhalia mutaciis gareshe 

Ixvniskarta Ikhvi4 aris mamrobiti 0 wlis,
aris 2.304000 kilogrami da Tsotskhalia mutaciis gareshe 
- - - - - - - - - - - - - - - - 

Ixvniskarta Ikhvi1 aris mamrobiti 0 wlis,
aris 3.936000 kilogrami da Tsotskhalia mutaciis gareshe 

Ixvniskarta Ikhvi4 aris mamrobiti 0 wlis,
aris 2.304000 kilogrami da Mkvdaria :( mutaciis gareshe 
--------------------------------
```