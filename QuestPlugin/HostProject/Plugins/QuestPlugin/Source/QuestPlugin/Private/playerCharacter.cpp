// Fill out your copyright notice in the Description page of Project Settings.


#include "playerCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AplayerCharacter::AplayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AplayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AplayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AplayerCharacter::EnterOtherActor(AActor* QuestActor)
{
	bool IsInterface = UKismetSystemLibrary::DoesImplementInterface(QuestActor, UInteractable::StaticClass());
	if (IsInterface)
	{
		m_currentActor = QuestActor;
		m_currentInteractive = Cast<IInteractable>(QuestActor);
	}
}

void AplayerCharacter::OnLeaveActor()
{
	m_currentInteractive = nullptr;
	m_currentActor = nullptr;
}

void AplayerCharacter::Action()
{
	if (m_currentInteractive != nullptr)
	{
		IInteractable::Execute_OnInteract(m_currentActor);
	}
}

