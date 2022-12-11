// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interactable.h"
#include "playerCharacter.generated.h"

UCLASS()
class QUESTPLUGIN_API AplayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AplayerCharacter();
	// Called every frame
    virtual void Tick(float DeltaTime) override;

    //interactions
    void EnterOtherActor(AActor* QuestActor);
    void OnLeaveActor();
    UFUNCTION(BlueprintCallable, Category = "Interact")
    void Action();
    
    //UI
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void ShowUI(FName character);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Events")
	void OnShowUpdatedQuestList(const TArray<FText>& questTextList);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//interacts
	AActor* m_currentActor;
	IInteractable* m_currentInteractive;

};
