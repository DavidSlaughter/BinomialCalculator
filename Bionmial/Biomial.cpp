#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
using namespace std;

void welcome()
{
   cout << "\nTell me the number of trials, probability of success of one trial, and number of successes." << endl;
   cout << "I will tell you the probability of that outcome!\n" << endl;   
}

float factorial(float x)        // Factorial function, takes integer input, stores its factorial.
{
    float factorialx=1;
    while (x>1)
    {
        factorialx = factorialx*x;
        x--;
    }

    return factorialx;
}

float binformula(float trials, float successes, float probabilitysuccess)   // This hasn't been used unfortunately :(
    {
        float p = pow(probabilitysuccess, successes) * pow(1-probabilitysuccess, trials-successes) * factorial(trials) / factorial(successes) / factorial(trials-successes);
        return p;
    }


class Binomial          // Class Binomial

{

    public:
    int Ntrials=0;
    int Nsuccesses=0;
    float Psuccess=0;

    void Set_Ntrials(int x)
    {
        Ntrials = x;
    }
    int Get_Ntrials()
    {
        return Ntrials;
    }
    void Set_Nsuccesses(int x)
    {
        Nsuccesses = x;
    }
    int Get_Nsuccesses()
    {
        return Nsuccesses;
    }
    void Set_Psuccess(float x)
    {
        Psuccess = x;
    }
    float Get_Psuccess()
    {
        return Psuccess;
    }

};  



int main()
{
   while (true){
    welcome();
    Binomial binomial;          // Creating an object from the class Binomial. 

    float a,b,c;                // Taking in user input for the variables and has error catches. 
    cout << "What is the number of trials? (max 34): "; cin >> a;  
    if (a>34 || a<0){cout << "\nYou can't enter a number > 34 or < 0. Todd Howard has now corrupted the program and it must end in 5 seconds..."; _sleep(5000); exit(EXIT_FAILURE);}
    cout << "What is the number of successes? (must be <= number of trials): "; cin >> b; 
    if (b>a || b<0){cout << "\nIn life, your success cannot be higher than your attempts. Unless you're an e-girl. The program will now end in 8 seconds..."; _sleep(8000); exit(EXIT_FAILURE);}
    cout << "What is the probability of success of 1 trial? (enter a number between 0 and 1): "; cin >> c; cout << endl;
    if (c<0 || c>1){cout << "The only probability lower than 0 is my chances of getting hired. The only probability greater than 1 is you dying and being forever alone in the darkness and vastness of this universe. Next time, enter a probability between 0 and 1. The program will now end in 15 seconds..."; _sleep(15000); exit(EXIT_FAILURE);}
    binomial.Set_Ntrials(a); binomial.Set_Nsuccesses(b); binomial.Set_Psuccess(c);      // Sets the variables based on user input.
    
    cout << "Would you like probabilities of successes up to and including your number of successes? Type '1' for yes or '0' for no: ";
    int z; cin >> z;        // Two paths based on if the user wants P(X<=x) or just P(X=x)


    if (z==0)       // The case when the user just wants P(X=x)
    {
        float p=0;      // Within this if statement is the binomial formula. Pausing here because this is the most important part of the program.
        p = p + ( pow(binomial.Get_Psuccess(), binomial.Get_Nsuccesses()) * pow(1-binomial.Get_Psuccess(), binomial.Get_Ntrials()-binomial.Get_Nsuccesses()) * factorial(binomial.Get_Ntrials()) / (factorial(binomial.Get_Nsuccesses())*factorial(binomial.Get_Ntrials()-binomial.Get_Nsuccesses())) );
        cout << "\n\nProbability of outcome: " << fixed << setprecision(12) << p*100 << " %";
        cout << endl; cout << endl; _sleep(1800);
    }

    else if(z==1)
    {
        float p=0;
        for (int x=0; x<=binomial.Get_Nsuccesses(); x++)
        {          
            p = p + ( pow(binomial.Get_Psuccess(), x) * pow(1-binomial.Get_Psuccess(), binomial.Get_Ntrials()-x) * factorial(binomial.Get_Ntrials()) / (factorial(x)*factorial(binomial.Get_Ntrials()-x)) );      
        }
        cout << "\n\nProbability of outcome: " << fixed << setprecision(12) << p*100 << " %";
        cout << endl; cout << endl; _sleep(1800);
    }
    else {cout << "\nYou didn't type a 0 or 1. YOU HAD ONE JOB.\n" << endl;}

   }
    return 0;
}













/*
    cout << "Would you like probabilities of successes up to and including your number of successes? Type '1' for yes or '0' for no: " << endl;
    int z; cin >> z;
    
    if (z=0)
    {
        int p;
        p = pow(Psuccess, Nsuccesses) * pow(1-Psuccess, Ntrials-Nsuccesses) * factorial(Ntrials) / (factorial(Nsuccesses)*factorial(Ntrials - Nsuccesses));
    }

    else
    {
        int p=1;
        for (int x=0; x<Nsuccesses; x++)
        {
            p = p * pow(Psuccess, Nsuccesses-x) * pow(1-Psuccess, Ntrials-Nsuccesses-x) * factorial(Ntrials) / (factorial(Nsuccesses-x)*factorial(Ntrials - Nsuccesses-x));
        }
    }
    
    cout << p;

    return 0;
}
*/