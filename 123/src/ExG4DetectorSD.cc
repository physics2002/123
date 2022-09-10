#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include "ExG4DetectorSD.hh"

#include<G4UserRunAction.hh>
#include<G4Run.hh>

using namespace std;

// Конструктор чуствительной области, по умолчанию инициализируем нижнюю и верхнюю
// границы гистограммы в 0 и 50 МэВ
//ofstream out("deltae.csv");

ExG4DetectorSD::ExG4DetectorSD(G4String name): G4VSensitiveDetector(name)
{
}

G4bool ExG4DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory*)
   {
         // Получаем кинетическую энергии частицы с предыдущего шага, т.е. начальную
       // кинитическую энегрию перед текущим шагом
       double energy = step->GetPreStepPoint()->GetKineticEnergy();
       
       G4TouchableHandle touchable = step->GetPreStepPoint()->GetTouchableHandle();
       G4VPhysicalVolume* volume = touchable->GetVolume();
       G4String name = volume->GetName();
       
       //Получаем выделившуюся энергию
       G4double edep = step->GetTotalEnergyDeposit();
       
            
       if (edep==0.) return false;

    if (edep < 0.3){
        G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    
        G4AnalysisManager *man = G4AnalysisManager::Instance();
        man->FillNtupleIColumn(0, evt);
        man->FillNtupleDColumn(1, edep);
        man->AddNtupleRow(0);
    }
             return true;
       }

             ExG4DetectorSD::~ExG4DetectorSD()
             {
                 
                 
              }


