// Fill out your copyright notice in the Description page of Project Settings.


#include "BluePrintFuncLibA.h"

#include "Algo/Accumulate.h"

FString UBluePrintFuncLibA::GetMeg()
{
	return FString(TEXT("Hi All."));
}

double UBluePrintFuncLibA::GetPi()
{
	return Pi;	
}

FAverages UBluePrintFuncLibA::CalcAverages(const TArray<float>& Values)
{	
	TArray<float> TempValues = Values;
	TMap<float, int32> ModelMap;
	
	const int32 Total = TempValues.Num();	
	if(Total == 0) return FAverages();
	
	TempValues.Sort();
	
	float Sum = 0.0f; //Algo::Accumulate(TempValues, 0.0f);
	for(int32 i = 0; i<Total; i++)
	{
		Sum += TempValues[i];
		if(!ModelMap.Contains(TempValues[i]))
		{
			ModelMap.Add(TempValues[i], 0);	
		}
		ModelMap[TempValues[i]]++;
	}
	const float Mean = Sum / static_cast<float>(Total);
	const float Median =
		Total % 2 == 0 ?
			TempValues[Total/2] :
			static_cast<float>( TempValues[Total / 2] + TempValues[Total / 2 - 1] ) / 2.0;
	ModelMap.ValueSort([](const int32 A, const int32 B) { return A > B;});
	
	TArray<TPair<float, int32>> ModelPair = ModelMap.Array();
	float Model = 0.0;
	if(ModelPair[0].Value == 1)
	{
		Model = Mean;
	}
	else
	{
		int32 ModelEntries = 1;
		int32 ModelSum = ModelPair[0].Key;

		for(int32 i = 0; i < ModelPair.Num(); i++)
		{
			if(ModelPair[i].Value != ModelPair[0].Value) break;
			ModelSum += ModelPair[i].Key;
			ModelEntries++;
		}
		Model = static_cast<float>(ModelSum) / static_cast<float>(ModelEntries);
		
	}
	return  FAverages(Mean, Model, Median);
}
