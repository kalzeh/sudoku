/** @file */
#ifndef cmd_ui_H
#define cmd_ui_H
#pragma once

#include "ui.h"
#include <iostream>
#include <limits>

class CmdUI : public abstractUI {
    public:
        CmdUI(); 
        void clearScreen() override;
        void displayHeader() override;
        void displayMenu() override;
        void displayInstructions() override;
        void displayPlanszaMenu() override;
        void playerSolve() override;
        void generatePlansza(std::string level) override;
        void solvePlansza() override;
        void displayPlansza() override;
        void displayGeneratedPlansza() override;
        void displaySolvedPlansza() override;
};

#endif