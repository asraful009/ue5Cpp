// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BluePrintFuncLibA.generated.h"

USTRUCT(BlueprintType)
struct FAverages
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	float Mean = 0.0f;
	UPROPERTY(BlueprintReadOnly)
	float Model = 0.0f;
	UPROPERTY(BlueprintReadOnly)
	float Median = 0.0f;
	
	FAverages():
		Mean(0.0f),
		Model(0.0f),
		Median(0.0f) {}
	
	FAverages(const float Mean, const float Model, const float Median):
		Mean(Mean),
		Model(Model),
		Median(Median) {}
	
};

/**
 * 
 */
UCLASS()
class UE5CPP_API UBluePrintFuncLibA : public UBlueprintFunctionLibrary
{
	
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	static FString GetMeg();

	UFUNCTION(BlueprintCallable, BlueprintPure,
		meta=(ToolTip = "3.124..", CompactNodeTitle = "π"))
	static double GetPi();

	UFUNCTION(BlueprintCallable, meta=(ToolTip = "CalcAverages", CompactNodeTitle = "μ"))
	static FAverages CalcAverages(const TArray<float>& Values);
	
private:
	static constexpr double Pi = 3.141592653589793238462643383279502884197;
};
