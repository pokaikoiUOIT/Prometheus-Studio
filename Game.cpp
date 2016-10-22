// GDW GAME
// By: Mitchell Fukuzawa, Peter Okai-koi, Jon Oliver, Jon Waller, Noel Shere
// Project: Agarthan Assault
#include "Header.h"

int main()
{
	//Resizes Console Window
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, 0, 0, 800, 1050, TRUE);

	int valx1y1 = 0, valx2y1 = 0, valx3y1 = 0, valx4y1 = 0, valx5y1 = 0, valx6y1 = 0, valx7y1 = 0, valx8y1 = 0, valx9y1 = 0, valx10y1 = 0, valx11y1 = 0, valx12y1 = 0, valx13y1 = 0, valx14y1 = 0, valx15y1 = 0, valx16y1 = 0, valx17y1 = 0, valx18y1 = 0, valx19y1 = 0, valx20y1 = 0, valx21y1 = 0, valx22y1 = 0, valx23y1 = 0, valx24y1 = 0, valx25y1 = 0, valx26y1 = 0, valx27y1 = 0, valx28y1 = 0, valx29y1 = 0, valx30y1 = 0, valx31y1 = 0, valx32y1 = 0, valx33y1 = 0, valx34y1 = 0, valx35y1 = 0, valx36y1 = 0, valx37y1 = 0, valx38y1 = 0, valx39y1 = 0, valx40y1 = 0, valx41y1 = 0, valx42y1 = 0, valx43y1 = 0, valx44y1 = 0, valx45y1 = 0, valx46y1 = 0, valx47y1 = 0, valx48y1 = 0, valx49y1 = 0, valx50y1 = 0, valx51y1 = 0, valx52y1 = 0, valx53y1 = 0, valx54y1 = 0, valx55y1 = 0, valx56y1 = 0, valx57y1 = 0, valx58y1 = 0, valx59y1 = 0, valx60y1 = 0, valx61y1 = 0, valx62y1 = 0, valx63y1 = 0, valx64y1 = 0, valx65y1 = 0, valx66y1 = 0, valx67y1 = 0, valx68y1 = 0, valx69y1 = 0, valx70y1 = 0, valx71y1 = 0, valx72y1 = 0, valx73y1 = 0, valx74y1 = 0, valx75y1 = 0, valx76y1 = 0, valx77y1 = 0, valx78y1 = 0, valx79y1 = 0, valx80y1 = 0;
	int valx1y2 = 0, valx2y2 = 0, valx3y2 = 0, valx4y2 = 0, valx5y2 = 0, valx6y2 = 0, valx7y2 = 0, valx8y2 = 0, valx9y2 = 0, valx10y2 = 0, valx11y2 = 0, valx12y2 = 0, valx13y2 = 0, valx14y2 = 0, valx15y2 = 0, valx16y2 = 0, valx17y2 = 0, valx18y2 = 0, valx19y2 = 0, valx20y2 = 0, valx21y2 = 0, valx22y2 = 0, valx23y2 = 0, valx24y2 = 0, valx25y2 = 0, valx26y2 = 0, valx27y2 = 0, valx28y2 = 0, valx29y2 = 0, valx30y2 = 0, valx31y2 = 0, valx32y2 = 0, valx33y2 = 0, valx34y2 = 0, valx35y2 = 0, valx36y2 = 0, valx37y2 = 0, valx38y2 = 0, valx39y2 = 0, valx40y2 = 0, valx41y2 = 0, valx42y2 = 0, valx43y2 = 0, valx44y2 = 0, valx45y2 = 0, valx46y2 = 0, valx47y2 = 0, valx48y2 = 0, valx49y2 = 0, valx50y2 = 0, valx51y2 = 0, valx52y2 = 0, valx53y2 = 0, valx54y2 = 0, valx55y2 = 0, valx56y2 = 0, valx57y2 = 0, valx58y2 = 0, valx59y2 = 0, valx60y2 = 0, valx61y2 = 0, valx62y2 = 0, valx63y2 = 0, valx64y2 = 0, valx65y2 = 0, valx66y2 = 0, valx67y2 = 0, valx68y2 = 0, valx69y2 = 0, valx70y2 = 0, valx71y2 = 0, valx72y2 = 0, valx73y2 = 0, valx74y2 = 0, valx75y2 = 0, valx76y2 = 0, valx77y2 = 0, valx78y2 = 0, valx79y2 = 0, valx80y2 = 0;
	int valx1y3 = 0, valx2y3 = 0, valx3y3 = 0, valx4y3 = 0, valx5y3 = 0, valx6y3 = 0, valx7y3 = 0, valx8y3 = 0, valx9y3 = 0, valx10y3 = 0, valx11y3 = 0, valx12y3 = 0, valx13y3 = 0, valx14y3 = 0, valx15y3 = 0, valx16y3 = 0, valx17y3 = 0, valx18y3 = 0, valx19y3 = 0, valx20y3 = 0, valx21y3 = 0, valx22y3 = 0, valx23y3 = 0, valx24y3 = 0, valx25y3 = 0, valx26y3 = 0, valx27y3 = 0, valx28y3 = 0, valx29y3 = 0, valx30y3 = 0, valx31y3 = 0, valx32y3 = 0, valx33y3 = 0, valx34y3 = 0, valx35y3 = 0, valx36y3 = 0, valx37y3 = 0, valx38y3 = 0, valx39y3 = 0, valx40y3 = 0, valx41y3 = 0, valx42y3 = 0, valx43y3 = 0, valx44y3 = 0, valx45y3 = 0, valx46y3 = 0, valx47y3 = 0, valx48y3 = 0, valx49y3 = 0, valx50y3 = 0, valx51y3 = 0, valx52y3 = 0, valx53y3 = 0, valx54y3 = 0, valx55y3 = 0, valx56y3 = 0, valx57y3 = 0, valx58y3 = 0, valx59y3 = 0, valx60y3 = 0, valx61y3 = 0, valx62y3 = 0, valx63y3 = 0, valx64y3 = 0, valx65y3 = 0, valx66y3 = 0, valx67y3 = 0, valx68y3 = 0, valx69y3 = 0, valx70y3 = 0, valx71y3 = 0, valx72y3 = 0, valx73y3 = 0, valx74y3 = 0, valx75y3 = 0, valx76y3 = 0, valx77y3 = 0, valx78y3 = 0, valx79y3 = 0, valx80y3 = 0;
	int valx1y4 = 0, valx2y4 = 0, valx3y4 = 0, valx4y4 = 0, valx5y4 = 0, valx6y4 = 0, valx7y4 = 0, valx8y4 = 0, valx9y4 = 0, valx10y4 = 0, valx11y4 = 0, valx12y4 = 0, valx13y4 = 0, valx14y4 = 0, valx15y4 = 0, valx16y4 = 0, valx17y4 = 0, valx18y4 = 0, valx19y4 = 0, valx20y4 = 0, valx21y4 = 0, valx22y4 = 0, valx23y4 = 0, valx24y4 = 0, valx25y4 = 0, valx26y4 = 0, valx27y4 = 0, valx28y4 = 0, valx29y4 = 0, valx30y4 = 0, valx31y4 = 0, valx32y4 = 0, valx33y4 = 0, valx34y4 = 0, valx35y4 = 0, valx36y4 = 0, valx37y4 = 0, valx38y4 = 0, valx39y4 = 0, valx40y4 = 0, valx41y4 = 0, valx42y4 = 0, valx43y4 = 0, valx44y4 = 0, valx45y4 = 0, valx46y4 = 0, valx47y4 = 0, valx48y4 = 0, valx49y4 = 0, valx50y4 = 0, valx51y4 = 0, valx52y4 = 0, valx53y4 = 0, valx54y4 = 0, valx55y4 = 0, valx56y4 = 0, valx57y4 = 0, valx58y4 = 0, valx59y4 = 0, valx60y4 = 0, valx61y4 = 0, valx62y4 = 0, valx63y4 = 0, valx64y4 = 0, valx65y4 = 0, valx66y4 = 0, valx67y4 = 0, valx68y4 = 0, valx69y4 = 0, valx70y4 = 0, valx71y4 = 0, valx72y4 = 0, valx73y4 = 0, valx74y4 = 0, valx75y4 = 0, valx76y4 = 0, valx77y4 = 0, valx78y4 = 0, valx79y4 = 0, valx80y4 = 0;
	int valx1y5 = 0, valx2y5 = 0, valx3y5 = 0, valx4y5 = 0, valx5y5 = 0, valx6y5 = 0, valx7y5 = 0, valx8y5 = 0, valx9y5 = 0, valx10y5 = 0, valx11y5 = 0, valx12y5 = 0, valx13y5 = 0, valx14y5 = 0, valx15y5 = 0, valx16y5 = 0, valx17y5 = 0, valx18y5 = 0, valx19y5 = 0, valx20y5 = 0, valx21y5 = 0, valx22y5 = 0, valx23y5 = 0, valx24y5 = 0, valx25y5 = 0, valx26y5 = 0, valx27y5 = 0, valx28y5 = 0, valx29y5 = 0, valx30y5 = 0, valx31y5 = 0, valx32y5 = 0, valx33y5 = 0, valx34y5 = 0, valx35y5 = 0, valx36y5 = 0, valx37y5 = 0, valx38y5 = 0, valx39y5 = 0, valx40y5 = 0, valx41y5 = 0, valx42y5 = 0, valx43y5 = 0, valx44y5 = 0, valx45y5 = 0, valx46y5 = 0, valx47y5 = 0, valx48y5 = 0, valx49y5 = 0, valx50y5 = 0, valx51y5 = 0, valx52y5 = 0, valx53y5 = 0, valx54y5 = 0, valx55y5 = 0, valx56y5 = 0, valx57y5 = 0, valx58y5 = 0, valx59y5 = 0, valx60y5 = 0, valx61y5 = 0, valx62y5 = 0, valx63y5 = 0, valx64y5 = 0, valx65y5 = 0, valx66y5 = 0, valx67y5 = 0, valx68y5 = 0, valx69y5 = 0, valx70y5 = 0, valx71y5 = 0, valx72y5 = 0, valx73y5 = 0, valx74y5 = 0, valx75y5 = 0, valx76y5 = 0, valx77y5 = 0, valx78y5 = 0, valx79y5 = 0, valx80y5 = 0;
	int valx1y6 = 0, valx2y6 = 0, valx3y6 = 0, valx4y6 = 0, valx5y6 = 0, valx6y6 = 0, valx7y6 = 0, valx8y6 = 0, valx9y6 = 0, valx10y6 = 0, valx11y6 = 0, valx12y6 = 0, valx13y6 = 0, valx14y6 = 0, valx15y6 = 0, valx16y6 = 0, valx17y6 = 0, valx18y6 = 0, valx19y6 = 0, valx20y6 = 0, valx21y6 = 0, valx22y6 = 0, valx23y6 = 0, valx24y6 = 0, valx25y6 = 0, valx26y6 = 0, valx27y6 = 0, valx28y6 = 0, valx29y6 = 0, valx30y6 = 0, valx31y6 = 0, valx32y6 = 0, valx33y6 = 0, valx34y6 = 0, valx35y6 = 0, valx36y6 = 0, valx37y6 = 0, valx38y6 = 0, valx39y6 = 0, valx40y6 = 0, valx41y6 = 0, valx42y6 = 0, valx43y6 = 0, valx44y6 = 0, valx45y6 = 0, valx46y6 = 0, valx47y6 = 0, valx48y6 = 0, valx49y6 = 0, valx50y6 = 0, valx51y6 = 0, valx52y6 = 0, valx53y6 = 0, valx54y6 = 0, valx55y6 = 0, valx56y6 = 0, valx57y6 = 0, valx58y6 = 0, valx59y6 = 0, valx60y6 = 0, valx61y6 = 0, valx62y6 = 0, valx63y6 = 0, valx64y6 = 0, valx65y6 = 0, valx66y6 = 0, valx67y6 = 0, valx68y6 = 0, valx69y6 = 0, valx70y6 = 0, valx71y6 = 0, valx72y6 = 0, valx73y6 = 0, valx74y6 = 0, valx75y6 = 0, valx76y6 = 0, valx77y6 = 0, valx78y6 = 0, valx79y6 = 0, valx80y6 = 0;
	int valx1y7 = 0, valx2y7 = 0, valx3y7 = 0, valx4y7 = 0, valx5y7 = 0, valx6y7 = 0, valx7y7 = 0, valx8y7 = 0, valx9y7 = 0, valx10y7 = 0, valx11y7 = 0, valx12y7 = 0, valx13y7 = 0, valx14y7 = 0, valx15y7 = 0, valx16y7 = 0, valx17y7 = 0, valx18y7 = 0, valx19y7 = 0, valx20y7 = 0, valx21y7 = 0, valx22y7 = 0, valx23y7 = 0, valx24y7 = 0, valx25y7 = 0, valx26y7 = 0, valx27y7 = 0, valx28y7 = 0, valx29y7 = 0, valx30y7 = 0, valx31y7 = 0, valx32y7 = 0, valx33y7 = 0, valx34y7 = 0, valx35y7 = 0, valx36y7 = 0, valx37y7 = 0, valx38y7 = 0, valx39y7 = 0, valx40y7 = 0, valx41y7 = 0, valx42y7 = 0, valx43y7 = 0, valx44y7 = 0, valx45y7 = 0, valx46y7 = 0, valx47y7 = 0, valx48y7 = 0, valx49y7 = 0, valx50y7 = 0, valx51y7 = 0, valx52y7 = 0, valx53y7 = 0, valx54y7 = 0, valx55y7 = 0, valx56y7 = 0, valx57y7 = 0, valx58y7 = 0, valx59y7 = 0, valx60y7 = 0, valx61y7 = 0, valx62y7 = 0, valx63y7 = 0, valx64y7 = 0, valx65y7 = 0, valx66y7 = 0, valx67y7 = 0, valx68y7 = 0, valx69y7 = 0, valx70y7 = 0, valx71y7 = 0, valx72y7 = 0, valx73y7 = 0, valx74y7 = 0, valx75y7 = 0, valx76y7 = 0, valx77y7 = 0, valx78y7 = 0, valx79y7 = 0, valx80y7 = 0;
	int valx1y8 = 0, valx2y8 = 0, valx3y8 = 0, valx4y8 = 0, valx5y8 = 0, valx6y8 = 0, valx7y8 = 0, valx8y8 = 0, valx9y8 = 0, valx10y8 = 0, valx11y8 = 0, valx12y8 = 0, valx13y8 = 0, valx14y8 = 0, valx15y8 = 0, valx16y8 = 0, valx17y8 = 0, valx18y8 = 0, valx19y8 = 0, valx20y8 = 0, valx21y8 = 0, valx22y8 = 0, valx23y8 = 0, valx24y8 = 0, valx25y8 = 0, valx26y8 = 0, valx27y8 = 0, valx28y8 = 0, valx29y8 = 0, valx30y8 = 0, valx31y8 = 0, valx32y8 = 0, valx33y8 = 0, valx34y8 = 0, valx35y8 = 0, valx36y8 = 0, valx37y8 = 0, valx38y8 = 0, valx39y8 = 0, valx40y8 = 0, valx41y8 = 0, valx42y8 = 0, valx43y8 = 0, valx44y8 = 0, valx45y8 = 0, valx46y8 = 0, valx47y8 = 0, valx48y8 = 0, valx49y8 = 0, valx50y8 = 0, valx51y8 = 0, valx52y8 = 0, valx53y8 = 0, valx54y8 = 0, valx55y8 = 0, valx56y8 = 0, valx57y8 = 0, valx58y8 = 0, valx59y8 = 0, valx60y8 = 0, valx61y8 = 0, valx62y8 = 0, valx63y8 = 0, valx64y8 = 0, valx65y8 = 0, valx66y8 = 0, valx67y8 = 0, valx68y8 = 0, valx69y8 = 0, valx70y8 = 0, valx71y8 = 0, valx72y8 = 0, valx73y8 = 0, valx74y8 = 0, valx75y8 = 0, valx76y8 = 0, valx77y8 = 0, valx78y8 = 0, valx79y8 = 0, valx80y8 = 0;
	int valx1y9 = 0, valx2y9 = 0, valx3y9 = 0, valx4y9 = 0, valx5y9 = 0, valx6y9 = 0, valx7y9 = 0, valx8y9 = 0, valx9y9 = 0, valx10y9 = 0, valx11y9 = 0, valx12y9 = 0, valx13y9 = 0, valx14y9 = 0, valx15y9 = 0, valx16y9 = 0, valx17y9 = 0, valx18y9 = 0, valx19y9 = 0, valx20y9 = 0, valx21y9 = 0, valx22y9 = 0, valx23y9 = 0, valx24y9 = 0, valx25y9 = 0, valx26y9 = 0, valx27y9 = 0, valx28y9 = 0, valx29y9 = 0, valx30y9 = 0, valx31y9 = 0, valx32y9 = 0, valx33y9 = 0, valx34y9 = 0, valx35y9 = 0, valx36y9 = 0, valx37y9 = 0, valx38y9 = 0, valx39y9 = 0, valx40y9 = 0, valx41y9 = 0, valx42y9 = 0, valx43y9 = 0, valx44y9 = 0, valx45y9 = 0, valx46y9 = 0, valx47y9 = 0, valx48y9 = 0, valx49y9 = 0, valx50y9 = 0, valx51y9 = 0, valx52y9 = 0, valx53y9 = 0, valx54y9 = 0, valx55y9 = 0, valx56y9 = 0, valx57y9 = 0, valx58y9 = 0, valx59y9 = 0, valx60y9 = 0, valx61y9 = 0, valx62y9 = 0, valx63y9 = 0, valx64y9 = 0, valx65y9 = 0, valx66y9 = 0, valx67y9 = 0, valx68y9 = 0, valx69y9 = 0, valx70y9 = 0, valx71y9 = 0, valx72y9 = 0, valx73y9 = 0, valx74y9 = 0, valx75y9 = 0, valx76y9 = 0, valx77y9 = 0, valx78y9 = 0, valx79y9 = 0, valx80y9 = 0;
	int valx1y10 = 0, valx2y10 = 0, valx3y10 = 0, valx4y10 = 0, valx5y10 = 0, valx6y10 = 0, valx7y10 = 0, valx8y10 = 0, valx9y10 = 0, valx10y10 = 0, valx11y10 = 0, valx12y10 = 0, valx13y10 = 0, valx14y10 = 0, valx15y10 = 0, valx16y10 = 0, valx17y10 = 0, valx18y10 = 0, valx19y10 = 0, valx20y10 = 0, valx21y10 = 0, valx22y10 = 0, valx23y10 = 0, valx24y10 = 0, valx25y10 = 0, valx26y10 = 0, valx27y10 = 0, valx28y10 = 0, valx29y10 = 0, valx30y10 = 0, valx31y10 = 0, valx32y10 = 0, valx33y10 = 0, valx34y10 = 0, valx35y10 = 0, valx36y10 = 0, valx37y10 = 0, valx38y10 = 0, valx39y10 = 0, valx40y10 = 0, valx41y10 = 0, valx42y10 = 0, valx43y10 = 0, valx44y10 = 0, valx45y10 = 0, valx46y10 = 0, valx47y10 = 0, valx48y10 = 0, valx49y10 = 0, valx50y10 = 0, valx51y10 = 0, valx52y10 = 0, valx53y10 = 0, valx54y10 = 0, valx55y10 = 0, valx56y10 = 0, valx57y10 = 0, valx58y10 = 0, valx59y10 = 0, valx60y10 = 0, valx61y10 = 0, valx62y10 = 0, valx63y10 = 0, valx64y10 = 0, valx65y10 = 0, valx66y10 = 0, valx67y10 = 0, valx68y10 = 0, valx69y10 = 0, valx70y10 = 0, valx71y10 = 0, valx72y10 = 0, valx73y10 = 0, valx74y10 = 0, valx75y10 = 0, valx76y10 = 0, valx77y10 = 0, valx78y10 = 0, valx79y10 = 0, valx80y10 = 0;
	int valx1y11 = 0, valx2y11 = 0, valx3y11 = 0, valx4y11 = 0, valx5y11 = 0, valx6y11 = 0, valx7y11 = 0, valx8y11 = 0, valx9y11 = 0, valx10y11 = 0, valx11y11 = 0, valx12y11 = 0, valx13y11 = 0, valx14y11 = 0, valx15y11 = 0, valx16y11 = 0, valx17y11 = 0, valx18y11 = 0, valx19y11 = 0, valx20y11 = 0, valx21y11 = 0, valx22y11 = 0, valx23y11 = 0, valx24y11 = 0, valx25y11 = 0, valx26y11 = 0, valx27y11 = 0, valx28y11 = 0, valx29y11 = 0, valx30y11 = 0, valx31y11 = 0, valx32y11 = 0, valx33y11 = 0, valx34y11 = 0, valx35y11 = 0, valx36y11 = 0, valx37y11 = 0, valx38y11 = 0, valx39y11 = 0, valx40y11 = 0, valx41y11 = 0, valx42y11 = 0, valx43y11 = 0, valx44y11 = 0, valx45y11 = 0, valx46y11 = 0, valx47y11 = 0, valx48y11 = 0, valx49y11 = 0, valx50y11 = 0, valx51y11 = 0, valx52y11 = 0, valx53y11 = 0, valx54y11 = 0, valx55y11 = 0, valx56y11 = 0, valx57y11 = 0, valx58y11 = 0, valx59y11 = 0, valx60y11 = 0, valx61y11 = 0, valx62y11 = 0, valx63y11 = 0, valx64y11 = 0, valx65y11 = 0, valx66y11 = 0, valx67y11 = 0, valx68y11 = 0, valx69y11 = 0, valx70y11 = 0, valx71y11 = 0, valx72y11 = 0, valx73y11 = 0, valx74y11 = 0, valx75y11 = 0, valx76y11 = 0, valx77y11 = 0, valx78y11 = 0, valx79y11 = 0, valx80y11 = 0;
	int valx1y12 = 0, valx2y12 = 0, valx3y12 = 0, valx4y12 = 0, valx5y12 = 0, valx6y12 = 0, valx7y12 = 0, valx8y12 = 0, valx9y12 = 0, valx10y12 = 0, valx11y12 = 0, valx12y12 = 0, valx13y12 = 0, valx14y12 = 0, valx15y12 = 0, valx16y12 = 0, valx17y12 = 0, valx18y12 = 0, valx19y12 = 0, valx20y12 = 0, valx21y12 = 0, valx22y12 = 0, valx23y12 = 0, valx24y12 = 0, valx25y12 = 0, valx26y12 = 0, valx27y12 = 0, valx28y12 = 0, valx29y12 = 0, valx30y12 = 0, valx31y12 = 0, valx32y12 = 0, valx33y12 = 0, valx34y12 = 0, valx35y12 = 0, valx36y12 = 0, valx37y12 = 0, valx38y12 = 0, valx39y12 = 0, valx40y12 = 0, valx41y12 = 0, valx42y12 = 0, valx43y12 = 0, valx44y12 = 0, valx45y12 = 0, valx46y12 = 0, valx47y12 = 0, valx48y12 = 0, valx49y12 = 0, valx50y12 = 0, valx51y12 = 0, valx52y12 = 0, valx53y12 = 0, valx54y12 = 0, valx55y12 = 0, valx56y12 = 0, valx57y12 = 0, valx58y12 = 0, valx59y12 = 0, valx60y12 = 0, valx61y12 = 0, valx62y12 = 0, valx63y12 = 0, valx64y12 = 0, valx65y12 = 0, valx66y12 = 0, valx67y12 = 0, valx68y12 = 0, valx69y12 = 0, valx70y12 = 0, valx71y12 = 0, valx72y12 = 0, valx73y12 = 0, valx74y12 = 0, valx75y12 = 0, valx76y12 = 0, valx77y12 = 0, valx78y12 = 0, valx79y12 = 0, valx80y12 = 0;
	int valx1y13 = 0, valx2y13 = 0, valx3y13 = 0, valx4y13 = 0, valx5y13 = 0, valx6y13 = 0, valx7y13 = 0, valx8y13 = 0, valx9y13 = 0, valx10y13 = 0, valx11y13 = 0, valx12y13 = 0, valx13y13 = 0, valx14y13 = 0, valx15y13 = 0, valx16y13 = 0, valx17y13 = 0, valx18y13 = 0, valx19y13 = 0, valx20y13 = 0, valx21y13 = 0, valx22y13 = 0, valx23y13 = 0, valx24y13 = 0, valx25y13 = 0, valx26y13 = 0, valx27y13 = 0, valx28y13 = 0, valx29y13 = 0, valx30y13 = 0, valx31y13 = 0, valx32y13 = 0, valx33y13 = 0, valx34y13 = 0, valx35y13 = 0, valx36y13 = 0, valx37y13 = 0, valx38y13 = 0, valx39y13 = 0, valx40y13 = 0, valx41y13 = 0, valx42y13 = 0, valx43y13 = 0, valx44y13 = 0, valx45y13 = 0, valx46y13 = 0, valx47y13 = 0, valx48y13 = 0, valx49y13 = 0, valx50y13 = 0, valx51y13 = 0, valx52y13 = 0, valx53y13 = 0, valx54y13 = 0, valx55y13 = 0, valx56y13 = 0, valx57y13 = 0, valx58y13 = 0, valx59y13 = 0, valx60y13 = 0, valx61y13 = 0, valx62y13 = 0, valx63y13 = 0, valx64y13 = 0, valx65y13 = 0, valx66y13 = 0, valx67y13 = 0, valx68y13 = 0, valx69y13 = 0, valx70y13 = 0, valx71y13 = 0, valx72y13 = 0, valx73y13 = 0, valx74y13 = 0, valx75y13 = 0, valx76y13 = 0, valx77y13 = 0, valx78y13 = 0, valx79y13 = 0, valx80y13 = 0;
	int valx1y14 = 0, valx2y14 = 0, valx3y14 = 0, valx4y14 = 0, valx5y14 = 0, valx6y14 = 0, valx7y14 = 0, valx8y14 = 0, valx9y14 = 0, valx10y14 = 0, valx11y14 = 0, valx12y14 = 0, valx13y14 = 0, valx14y14 = 0, valx15y14 = 0, valx16y14 = 0, valx17y14 = 0, valx18y14 = 0, valx19y14 = 0, valx20y14 = 0, valx21y14 = 0, valx22y14 = 0, valx23y14 = 0, valx24y14 = 0, valx25y14 = 0, valx26y14 = 0, valx27y14 = 0, valx28y14 = 0, valx29y14 = 0, valx30y14 = 0, valx31y14 = 0, valx32y14 = 0, valx33y14 = 0, valx34y14 = 0, valx35y14 = 0, valx36y14 = 0, valx37y14 = 0, valx38y14 = 0, valx39y14 = 0, valx40y14 = 0, valx41y14 = 0, valx42y14 = 0, valx43y14 = 0, valx44y14 = 0, valx45y14 = 0, valx46y14 = 0, valx47y14 = 0, valx48y14 = 0, valx49y14 = 0, valx50y14 = 0, valx51y14 = 0, valx52y14 = 0, valx53y14 = 0, valx54y14 = 0, valx55y14 = 0, valx56y14 = 0, valx57y14 = 0, valx58y14 = 0, valx59y14 = 0, valx60y14 = 0, valx61y14 = 0, valx62y14 = 0, valx63y14 = 0, valx64y14 = 0, valx65y14 = 0, valx66y14 = 0, valx67y14 = 0, valx68y14 = 0, valx69y14 = 0, valx70y14 = 0, valx71y14 = 0, valx72y14 = 0, valx73y14 = 0, valx74y14 = 0, valx75y14 = 0, valx76y14 = 0, valx77y14 = 0, valx78y14 = 0, valx79y14 = 0, valx80y14 = 0;
	int valx1y15 = 0, valx2y15 = 0, valx3y15 = 0, valx4y15 = 0, valx5y15 = 0, valx6y15 = 0, valx7y15 = 0, valx8y15 = 0, valx9y15 = 0, valx10y15 = 0, valx11y15 = 0, valx12y15 = 0, valx13y15 = 0, valx14y15 = 0, valx15y15 = 0, valx16y15 = 0, valx17y15 = 0, valx18y15 = 0, valx19y15 = 0, valx20y15 = 0, valx21y15 = 0, valx22y15 = 0, valx23y15 = 0, valx24y15 = 0, valx25y15 = 0, valx26y15 = 0, valx27y15 = 0, valx28y15 = 0, valx29y15 = 0, valx30y15 = 0, valx31y15 = 0, valx32y15 = 0, valx33y15 = 0, valx34y15 = 0, valx35y15 = 0, valx36y15 = 0, valx37y15 = 0, valx38y15 = 0, valx39y15 = 0, valx40y15 = 0, valx41y15 = 0, valx42y15 = 0, valx43y15 = 0, valx44y15 = 0, valx45y15 = 0, valx46y15 = 0, valx47y15 = 0, valx48y15 = 0, valx49y15 = 0, valx50y15 = 0, valx51y15 = 0, valx52y15 = 0, valx53y15 = 0, valx54y15 = 0, valx55y15 = 0, valx56y15 = 0, valx57y15 = 0, valx58y15 = 0, valx59y15 = 0, valx60y15 = 0, valx61y15 = 0, valx62y15 = 0, valx63y15 = 0, valx64y15 = 0, valx65y15 = 0, valx66y15 = 0, valx67y15 = 0, valx68y15 = 0, valx69y15 = 0, valx70y15 = 0, valx71y15 = 0, valx72y15 = 0, valx73y15 = 0, valx74y15 = 0, valx75y15 = 0, valx76y15 = 0, valx77y15 = 0, valx78y15 = 0, valx79y15 = 0, valx80y15 = 0;

	//Values for each pixel (1 = white and 0 = black)
	int line01[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line02[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line03[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line04[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line05[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line06[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line07[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line08[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line09[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line10[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line11[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line12[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line13[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line14[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
	int line15[80] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };

	//line1
	int num = 0;
	for (int i = 0; i < 80; i += 1)
	{
		if (line01[num] == 1)
			white();
		else if (line01[num] == 0)
			black();
		num += 1;
	}
	
	//line2
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line02[num] == 1)
			white();
		else if (line02[num] == 0)
			black();
		num += 1;
	}

	//line3
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line03[num] == 1)
			white();
		else if (line03[num] == 0)
			black();
		num += 1;
	}

	//line4
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line04[num] == 1)
			white();
		else if (line04[num] == 0)
			black();
		num += 1;
	}

	//line5
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line05[num] == 1)
			white();
		else if (line05[num] == 0)
			black();
		num += 1;
	}

	//line6
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line06[num] == 1)
			white();
		else if (line06[num] == 0)
			black();
		num += 1;
	}

	//line7
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line07[num] == 1)
			white();
		else if (line07[num] == 0)
			black();
		num += 1;
	}

	//line8
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line08[num] == 1)
			white();
		else if (line08[num] == 0)
			black();
		num += 1;
	}

	//line9
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line09[num] == 1)
			white();
		else if (line09[num] == 0)
			black();
		num += 1;
	}

	//line10
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line10[num] == 1)
			white();
		else if (line10[num] == 0)
			black();
		num += 1;
	}

	//line11
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line11[num] == 1)
			white();
		else if (line11[num] == 0)
			black();
		num += 1;
	}

	//line12
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line12[num] == 1)
			white();
		else if (line12[num] == 0)
			black();
		num += 1;
	}

	//line13
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line13[num] == 1)
			white();
		else if (line13[num] == 0)
			black();
		num += 1;
	}

	//line14
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line14[num] == 1)
			white();
		else if (line14[num] == 0)
			black();
		num += 1;
	}

	//line15
	num = 0;
	for (int i = 0; i != 80; i += 1)
	{
		if (line15[num] == 1)
			white();
		else if (line15[num] == 0)
			black();
		num += 1;
	}

	//std::this_thread::sleep_for(std::chrono::seconds(1));
	system("PAUSE");
	return 0;
}