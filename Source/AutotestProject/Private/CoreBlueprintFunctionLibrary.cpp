// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreBlueprintFunctionLibrary.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Input/Events.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"


void UCoreBlueprintFunctionLibrary::TestClick(FVector2D Position, APlayerController* PlayerController) 
{
    FInputModeGameAndUI InputMode;
    PlayerController->SetInputMode(InputMode);

    FKey MouseButton = EKeys::LeftMouseButton;
    // Get the slate application.
    FSlateApplication& SlateApp = FSlateApplication::Get();

    FPointerEvent MouseEvent(0, Position, Position, TSet<FKey>(), MouseButton, 0, FModifierKeysState());
    TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();

    FSlateApplication::Get().ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);
    FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

   // FSlateApplication::Get().ProcessMouseButtonDoubleClickEvent(PlatformWindow, MouseEvent);
    //FSlateApplication::Get().ProcessMouseButtonUpEvent(MouseEvent);

   //PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);
   //PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);

   //UGameplayStatics::GetPlayerController(GWorld, 0)->Tap(Position, ETouchIndex::Touch1, 1.0f);
}
