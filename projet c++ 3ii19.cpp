#include <iostream>
#include <string>
#include <vector>

// ALI boilami && Yassir Nmar 
using namespace std;

// Classe representant un billet de train
class Billet {
private:
    string trainNumero;     
    string horaireDepart;   
    string destination;     
public:
   
    Billet(const string& trainNumero, const string& horaireDepart, const string& destination)
        : trainNumero(trainNumero), horaireDepart(horaireDepart), destination(destination) {}

   
    void afficherBillet() const {
        cout << "Billet - Train numero: " << trainNumero << ", Horaire de depart: " << horaireDepart
             << ", Destination: " << destination << endl;
    }
};

// class represantant un passager 
class Passager {
private:
    string nom;        
    Billet billet;     

public:
    
    Passager(const string& nom, const Billet& billet) : nom(nom), billet(billet) {}

 
    string getNom() const {
        return nom;
    }

  
    void afficherPassager() const {
        cout << "Passager: " << nom << endl;
        billet.afficherBillet();  
    }
};

// Classe representant un train
class Train {
private:
    string numero;             
    string horaireDepart;        
    string horaireArrivee;       
    vector<Passager> passagers;  

public:
  
    Train(const string& numero, const string& horaireDepart, const string& horaireArrivee)
        : numero(numero), horaireDepart(horaireDepart), horaireArrivee(horaireArrivee) {}

 
    Train& operator+=(const Passager& passager) {
        passagers.push_back(passager); 
        return *this;  
    }

 
    void afficherTrain() const {
        cout << "Train numero: " << numero << endl;
        cout << "Horaire de depart: " << horaireDepart << endl;
        cout << "Horaire d'arrivee: " << horaireArrivee << endl;
        cout << "Passagers: " << endl;
        for (const auto& passager : passagers) {
            cout << "  - " << passager.getNom() << endl;  
        }
    }
    
  
    void rechercherPassager(const string& nom) const {
        for (const auto& passager : passagers) {
            if (passager.getNom() == nom) {
                cout << "Passager trouve: " << endl;
                passager.afficherPassager();  
                return;
            }
        }
        cout << "Passager non trouve." << endl;  
    }

  
    int obtenirNombrePassagers() const {
        return passagers.size();
    }
};

// Classe représentant un train express qui hérite de la classe Train
class TrainExpress : public Train {
private:
    double vitesseMoyenne;  

public:

    TrainExpress(const string& numero, const string& horaireDepart, const string& horaireArrivee, double vitesseMoyenne)
        : Train(numero, horaireDepart, horaireArrivee), vitesseMoyenne(vitesseMoyenne) {}


    double getVitesseMoyenne() const {
        return vitesseMoyenne;
    }

    
    void afficherTrainExpress() const {
        afficherTrain();  // Affiche les détails du train
        cout << "Vitesse moyenne: " << vitesseMoyenne << " km/h" << endl;
    }
};

// Classe representant une gare
class Gare {
private:
    string nomGare;    
    vector<Train> trains;  

public:
   
    Gare(const string& nomGare) : nomGare(nomGare) {}


    void ajouterTrain(const Train& train) {
        trains.push_back(train);  
    }

    
    void afficherGare() const {
        cout << "Gare: " << nomGare << endl;
        for (const auto& train : trains) {
            train.afficherTrain(); 
            cout << "---------------------------" << endl;
        }
    }
};

int main() {
    // 1. Création des trains
    Train train1("Atlas1", "07:00", "10:00");
    Train train2("Tn1", "09:30", "12:45");
    TrainExpress express1("boraq1", "06:15", "08:15", 200.0);
    TrainExpress express2("boraq2", "14:00", "16:00", 250.0);
    
    // 2. Création des passagers avec des billets
    Billet billet1("Atlas1", "07:00", "Marrakesh");
    Billet billet2("Tn1", "09:30", "Kenitra");
    Billet billet3("boraq1", "06:15", "Rabat AGDAL");
    Billet billet4("boraq2", "14:00", "Tangier");
    Passager passager1("Mehdi", billet1);
    Passager passager2("Yassir", billet2);
    Passager passager3("Mariame", billet3);
    Passager passager4("Ali", billet4);
    
    // 3. Ajout des passagers aux trains
    train1 += passager1;
    train2 += passager2;
    express1 += passager3;
    express2 += passager4;
    
    // 4. Création d'une gare
    Gare gare("Gare Centrale");
    gare.ajouterTrain(train1);
    gare.ajouterTrain(train2);
    gare.ajouterTrain(express1);
    gare.ajouterTrain(express2);
    
    // 5. Affichage des détails
    cout << "=== Détails des Trains ===" << endl;
    train1.afficherTrain();
    cout << endl;
    train2.afficherTrain();
    cout << endl;
    cout << "=== Détails des Trains Express ===" << endl;
    express1.afficherTrainExpress();
    cout << endl;
    express2.afficherTrainExpress();
    cout << endl;
    cout << "=== Détails de la Gare ===" << endl;
    gare.afficherGare();
    
    cout << "Nombre de passagers dans le train Atlas1 : " << train1.obtenirNombrePassagers() << endl;
    cout << "Nombre de passagers dans le train Tn1 : " << train2.obtenirNombrePassagers() << endl;
    cout << "Nombre de passagers dans le train boraq1 : " << express1.obtenirNombrePassagers() << endl;
    cout << "Nombre de passagers dans le train boraq2 : " << express2.obtenirNombrePassagers() << endl;
    
    // Exemple de recherche de passager
    cout << "\n=== Recherche de passager ===" << endl;
    train1.rechercherPassager("Mehdi");
    train2.rechercherPassager("Ali");
    express1.rechercherPassager("Mariame");
    
    return 0;
}

