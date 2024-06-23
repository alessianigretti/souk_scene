// Project Sparrow - 2024.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "souk_scene/Abilities/SoukAbilitySystemComponent.h"
#include "souk_scene/Abilities/SoukAttributeSetBase.h"
#include "SoukAgent.generated.h"

class USoukAbilitySystemComponent;
class USoukAttributeSetBase;
class UGameplayAbility;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS(config = Game)
class SOUK_SCENE_API ASoukAgent : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASoukAgent();

	virtual void PossessedBy(AController* NewController) override;

	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	USoukAttributeSetBase* GetAttributeSetBase() const;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	USoukAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	USoukAttributeSetBase* AttributeSetBase;
};
