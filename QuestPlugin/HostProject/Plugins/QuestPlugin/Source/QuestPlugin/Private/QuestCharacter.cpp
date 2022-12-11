// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestCharacter.h"
#include "Components/BoxComponent.h"
#include "playerCharacter.h"
#include "QuestManager.h"

// Sets default values
AQuestCharacter::AQuestCharacter()
{
	//set up the trigger box to detect player
	m_trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	m_trigger->SetupAttachment(RootComponent);
	m_trigger->OnComponentBeginOverlap.AddUniqueDynamic(this, &AQuestCharacter::BeginOverlap);
	m_trigger->OnComponentEndOverlap.AddUniqueDynamic(this, &AQuestCharacter::EndOverlap);
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuestCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_questActivated = true;
	SetActorTickEnabled(true);

	m_questManager = Cast<AQuestManager>(GetWorld()->GetAuthGameMode());
}

// Called every frame
void AQuestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuestCharacter::OnInteract_Implementation()
{
	m_questManager->GiveQuest(m_questID);
	IInteractable::OnInteract_Implementation();
}

void AQuestCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AplayerCharacter* playerCharacter = Cast<AplayerCharacter>(OtherActor);
	if(playerCharacter!=nullptr)
	{
		m_playerCharacter = playerCharacter;
		m_playerCharacter->EnterOtherActor(this);
		m_playerCharacter->ShowUI(m_characterName);
		OnPlayerEnter();

	}
}

void AQuestCharacter::EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(m_playerCharacter != nullptr)
	{
		m_playerCharacter->OnLeaveActor();
	}
	m_playerCharacter = nullptr; //reset player character
}


