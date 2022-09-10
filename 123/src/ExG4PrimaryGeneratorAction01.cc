#include "ExG4PrimaryGeneratorAction01.hh"
// Подключаем необходимы заголовочные файлы
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// Класс, в котором описывается положение, тип, енергия частиц, направление вылета
// и распределенние начальных частиц

int iRun = 0;





ExG4PrimaryGeneratorAction01::ExG4PrimaryGeneratorAction01()
: G4VUserPrimaryGeneratorAction(),
  fParticleGun(0)
{
  // По умолчанию поставим 1 частицу
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
    
   
    
  // default particle kinematic
  // Получаем встроеную в Geant4 таблицу частиц
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  // Ищем частицу, в нашем случае электрон
  G4ParticleDefinition* particle
    = particleTable->FindParticle(particleName="proton");
  // Устанавливаем полученную частицу как испускаемые начальные частицы в источнике
  fParticleGun->SetParticleDefinition(particle);
  // Устанавливаем момент - направление движение частицы по (x,y,z)
  // Здесь установленно направление вдоль оси OZ
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  // Установка начальной энергии испускаемых частиц, 900 МэВ
  fParticleGun->SetParticleEnergy(900*MeV);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
// Деструктор, удаляем созданный в конструкторе экземпляр класса источника G4ParticleGun
ExG4PrimaryGeneratorAction01::~ExG4PrimaryGeneratorAction01()
{
  delete fParticleGun;
}



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ExG4PrimaryGeneratorAction01::GeneratePrimaries(G4Event* anEvent)
{
  //this function is called at the begining of ecah event
  //Эта функция вызывается в начале каждого первичного события
  // Задаем координаты источника частиц
//  G4double x0 = 0;
//  G4double y0 = 0;
// G4double z0 = -0.5 * 1.5*cm;
    

    G4double x0 = 0;
    G4double y0 = 0;
    G4double z0 = -0.5 * 1.5*cm;
    
    
  // Устанавливаем положение источника частиц
  fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  // Создаем начальное событие, запускаем первичную частицу
  fParticleGun->GeneratePrimaryVertex(anEvent);
    //G4cout << "*********************************************************************************************************\n";
    //G4cout << "\n #############" << " Run = " << iRun << " Starts #############" <<"\n";
    iRun++;
}
