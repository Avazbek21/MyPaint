//---------------------------------------------------------------------------

#ifndef pen1H
#define pen1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include "CGRID.h"
#include "CSPIN.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TMainMenu *MainMenu1;
    TMenuItem *Menu;
    TMenuItem *BCreate;
    TMenuItem *BOpen;
    TMenuItem *BSave;
    TMenuItem *BSaveas;
    TMenuItem *N5;
    TMenuItem *BExit;
    TOpenPictureDialog *OpenPictureDialog1;
    TSavePictureDialog *SavePictureDialog1;
    TCSpinEdit *CSpinEdit1;
    TSpeedButton *BPencil;
    TSpeedButton *BRectangle;
    TSpeedButton *BElleps;
    TSpeedButton *BEraser;
    TSpeedButton *BRectangleFill;
    TSpeedButton *BEllepsFill;
    TSpeedButton *BFill;
    TSpeedButton *BPipet;
    TRadioGroup *RadioGroup1;
    TImage *CColor1;
    TImage *CColor2;
    TLabel *Label1;
    TLabel *Label2;
    TColorDialog *ColorDialog1;
    void __fastcall BExitClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BPipetClick(TObject *Sender);
    void __fastcall BOpenClick(TObject *Sender);
    void __fastcall BCreateClick(TObject *Sender);
    void __fastcall BSaveClick(TObject *Sender);
    void __fastcall BSaveasClick(TObject *Sender);
    void __fastcall BPencilClick(TObject *Sender);
    void __fastcall BRectangleClick(TObject *Sender);
    void __fastcall BEllepsClick(TObject *Sender);
    void __fastcall BFillClick(TObject *Sender);
    void __fastcall BEraserClick(TObject *Sender);
    void __fastcall BRectangleFillClick(TObject *Sender);
    void __fastcall BEllepsFillClick(TObject *Sender);
    void __fastcall CSpinEdit1Change(TObject *Sender);
    void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall CColor1DblClick(TObject *Sender);
    void __fastcall CColor2DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
