// Fill out your copyright notice in the Description page of Project Settings.

#if WITH_AUTOMATION_TESTS
#include "Test/UITest.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tests/AutomationCommon.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Commands/GenericCommands.h"
#include "Input/Events.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"
#include "AutotestProject/TestUtils.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Async/Async.h"
#include "CoreBlueprintFunctionLibrary.h"

using namespace TPS::Test;

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FClickTest, "AutotestProject.UITest.Click",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMoveMouseTest, "AutotestProject.UITest.MoveMousePosition",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyAutomationTest, "AutotestProject.UITest.MoveMousePosition",
    EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter | EAutomationTestFlags::CriticalPriority);


// Custom latent command for moving the cursor
DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FMoveCursorCommand, FVector2D, ScreenPosition, APlayerController*, PlayerController);
bool FMoveCursorCommand::Update()
{
    PlayerController->SetMouseLocation(ScreenPosition.X, ScreenPosition.Y);
    UE_LOG(LogTemp, Log, TEXT("MoveCursorCommand"));
    return true;
}

DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FClickCursorCommand, FVector2D, ScreenPosition, APlayerController*, PlayerController);
bool FClickCursorCommand::Update()
{
    UCoreBlueprintFunctionLibrary::TestClick(ScreenPosition, PlayerController);
    //PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);
    //PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);

    UE_LOG(LogTemp, Log, TEXT("ClickCursorCommand"));
    return true;
}

/*
DEFINE_LATENT_AUTOMATION_COMMAND_TWO_PARAMETER(FGetWidgetByNameCommand, UUserWidget*, UserWidget, FName, WidgetName, );
bool FGetWidgetByNameCommand::Update()
{
    //UCoreBlueprintFunctionLibrary::TestClick(ScreenPosition, PlayerController);
    //PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Pressed, 0, false);
    // PlayerController->InputKey(FKey("LeftMouseButton"), EInputEvent::IE_Released, 0, false);

    //UserWidget = FindWidgetByName(UserWidget, WidgetName);
    return true;
}
*/

DEFINE_LATENT_AUTOMATION_COMMAND_ONE_PARAMETER(FSimulateMouseClick, FVector2D, ClickPosition);

bool FSimulateMouseClick::Update()
{
    FKey MouseButton = EKeys::LeftMouseButton;
    FSlateApplication& SlateApp = FSlateApplication::Get();

    FPointerEvent MouseEvent(0, ClickPosition, ClickPosition, TSet<FKey>(), MouseButton, 0, FModifierKeysState());
    TSharedPtr<FGenericWindow> PlatformWindow = FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow();
    // Simulate a mouse button press
    SlateApp.ProcessMouseButtonDownEvent(PlatformWindow, MouseEvent);

    // Simulate a mouse button release
    SlateApp.ProcessMouseButtonUpEvent(MouseEvent);

    return true;
}

bool FMyAutomationTest::RunTest(const FString& Parameters)
{
    // Specify the click position (screen coordinates)
    FVector2D ClickPosition(500, 500);  // Replace with your desired screen coordinates

    // Create and execute the latent command to simulate a mouse click
    ADD_LATENT_AUTOMATION_COMMAND(FSimulateMouseClick(ClickPosition));

    // Perform additional test actions and verifications here

    return true;  // Test passed
}

bool FClickTest::RunTest(const FString& Parameters) 
{
    const auto Level = LevelScope("/Game/Maps/TestLevel");

    UWorld* World = GetTestGameWorld();
    if (!TestNotNull("World exists", World)) return false;

    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(World, 0);
    if (!TestNotNull("Character exists", Character)) return false;

    FVector2D Position = FVector2D(100, 100);
    auto PlayerController = World->GetFirstPlayerController();
    if (!TestNotNull("PlayerController exists", PlayerController)) return false;
    PlayerController->SetShowMouseCursor(true);

    //UCoreBlueprintFunctionLibrary::TestClick(Position, PlayerController);

    ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(5.0f));
    ADD_LATENT_AUTOMATION_COMMAND(FMoveCursorCommand(Position, PlayerController));
    ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(5.f));

    ADD_LATENT_AUTOMATION_COMMAND(FClickCursorCommand(Position, PlayerController));
    ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(10.0f));

    UE_LOG(LogTemp, Log, TEXT("After wait"));
    return true;
}

bool FMoveMouseTest::RunTest(const FString& Parameters)
{
    FVector2D Position = FVector2D(100, 100);
    //MoveMouse(Position);
    return true;
}

bool MoveMouse(FVector2D& Position, UWorld* World)
{
    //FSlateApplication& SlateApp = FSlateApplication::Get();
    //SlateApp.SetCursorPos(Position);

    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(World, 0);
    if (!Character)
    {
        //if (!TestNotNull("Character exists", Character)) return false;
    }


    Character->GetLocalViewingPlayerController()->SetMouseLocation(Position.X, Position.Y);
    return true;
}
#endif