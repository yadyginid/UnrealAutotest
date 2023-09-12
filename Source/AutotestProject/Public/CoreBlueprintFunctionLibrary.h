// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CoreBlueprintFunctionLibrary.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AUTOTESTPROJECT_API UCoreBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Test")
    static void TestClick(FVector2D Position, APlayerController* PlayerController);

    UFUNCTION(BlueprintCallable, Category = "Test")
    static void TestClickOff(FVector2D Position, APlayerController* PlayerController);

    static void GetWidgetUnderCursor();

    UFUNCTION(BlueprintCallable, Category = "Test")
    static void ProcessEditorClick(FVector2D atCoordinates);
};
