#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Platypus {
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
//ფუნქცია print რომელიც გამოიტანს იხვნისკარტას შესახებ ინფორმაციას ლამაზი და ადვილად აღსაქმელი ფორმითა და ფორმატით.  :))))
         void print() {
            string gen = (gender == 'm') ? "mamrobiti" : "mdedrobiti";
            printf("\nIxvniskarta %s aris %s %d wlis,\n",name.c_str(),gen.c_str(),age);
            string life = (alive) ? "Tsotskhalia" : "Mkvdaria :(";
            string mutantS = (mutant) ? "mutaciit" : "mutaciis gareshe";
            printf("aris %f kilogrami da %s %s \n",weight,life.c_str(),mutantS.c_str());
         }

         /*
ეს ფუნქცია ზრდის იხვნისკარტას ასაკს და ასევე ითვალისწინებს იმას რომ არსებობს 2% შანსი იმისა რომ გახდეს მუტანტი.
იხვნისკარტას შანსი რომ მოკვდეს როცა წელს იმატებს ათჯერ მეტია მის წონაზე
         */
         void age_me(){
            if (alive == false)
            return ;
            age++;
            _generateMutation();
            _generateDeath();
         }
         /*
         შევქმენი ფუნქცია რომელიც იღებს იხვნისკარტას ობჯეკტს როგორც პარამეტრს მისი დანიშნულებაა ის იხვნისკარტა რომელიც ფუნქციას გადაეცემა
         რომ თავს დაესხას გამოძახებულ იხვნისკარტას
         გამოძახებული იხნისკარტას წონა უნდა გავყოთ მეორე იხვნისკარტას წონაზე და გავამრავლოთ 50 თუ მეტია 1-დან 100-მდე  შემთხვევითი რიცხვებისა მაშინ მეორე 
         იხნვისკარტა გადარჩება
         */
         void fight(Platypus * target){
            if(alive == false)
            return ;
            float fightRatio = (weight / target->getWeight()) * 50.0f;

            if (fightRatio > static_cast<float>(_grade()))
                target->die();
            else
                die();
         }
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
         /*
         hatch ფუნქცია რომელიც შექმნის ახალშობილ იხნვისკარტას და მიანიჭებას მას მონაცემებს alive=true, mutant=false, და age=0 სქესი იქნება ან 
         მამრობითი ან მდედრობითი ტოლი ალბათობით და ასევე წონა 0.1კგ - დან 1.0 კგმდე
         */
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
         ~Platypus(){}
         private:
         float weight;
         short age;
         string name;
         char gender;
         bool alive;
         bool mutant;
         const static int nameSize = 4;
         const string nameM[nameSize] = {"Ikhvi1","Ikhvi2","Ikhvi3","Ikhvi4"};
         const string nameF[nameSize] = {"Ikhvi01","Ikhvi02","Ikhvi03","Ikhvi04"};
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
         //შევქმნათ რანდომ რიცხვები 1 დან 100 მდე
         int _grade(){
            return ( rand() % 100 + 1 );
         }
};

        //კლასის ტესტირება
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