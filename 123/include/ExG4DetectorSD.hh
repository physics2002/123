#include <G4VSensitiveDetector.hh>
#ifndef ExG4DetectorSD_h
#define ExG4DetectorSD_h 1
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
   class G4Step;
   class G4TouchableHistory;
   
   class ExG4DetectorSD: public G4VSensitiveDetector
     {
     public:
       
        ExG4DetectorSD(G4String name);
       
        ~ExG4DetectorSD();
       
        G4bool ProcessHits(G4Step* step, G4TouchableHistory*);
        void EndOfEvent(int nEvent);
     };
#endif /* SENSITIVEDETECTOR */
