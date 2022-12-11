// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Character.h"
#include "QuestCharacter.generated.h"

UCLASS()
class QUESTPLUGIN_API AQuestCharacter : public ACharacter , public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AQuestCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Interaface
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interact")
	void OnInteract();

	//Actual implementation of the Interact
	void OnInteract_Implementation();

	UPROPERTY(EditAnywhere)
	class AQuestManager* m_questManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName m_characterName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "QuestCharacter")
	FName m_questID;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "QuestCharacter")
	class UBoxComponent* m_trigger;
	bool m_questActivated = false;


	//hit box
	class AplayerCharacter* m_playerCharacter; // stores the player when in range
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable,Category="QuestCharacter")
	void OnPlayerEnter();
	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
