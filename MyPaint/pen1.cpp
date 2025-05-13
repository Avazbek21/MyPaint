//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pen1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGRID"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
int paint=1, x, y, value=0;;
bool BMouse=false, MMove=false;
String picture;
int i=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender) //on create paint
{
Image1->Canvas->Brush->Style=bsClear;   //the drawing field is ready
BPencil->Flat=false;                    //selected pencil
CColor1->Canvas->Brush->Color=clBlack;
CColor1->Canvas->FillRect(CColor1->ClientRect);
CColor2->Canvas->Brush->Color=clWhite;
CColor2->Canvas->FillRect(CColor2->ClientRect);
Form1->DoubleBuffered=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BExitClick(TObject *Sender) //on close paint
{
Close(); // close program
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BCreateClick(TObject *Sender)  //create new picture
{
 if(Image1->Canvas->Brush->Style!=bsClear) {
     if (MessageBoxA(0,"Cохранить изображение","Paint",MB_YESNO|MB_ICONQUESTION)==IDYES){
         BSaveas->Click();
     }
 }
 Image1->Canvas->Brush->Style!=bsClear;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::BOpenClick(TObject *Sender)  //open picture
{
    if(OpenPictureDialog1->Execute()) {
        picture=OpenPictureDialog1->FileName;
        Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BSaveClick(TObject *Sender) //save picture
{
 if(picture!="")
     Image1->Picture->SaveToFile(picture);
 else
     BSaveas->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BSaveasClick(TObject *Sender) //save as picture
{
 if(SavePictureDialog1->Execute()) {
     picture=SavePictureDialog1->FileName.c_str();
     Image1->Picture->SaveToFile(picture);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BPencilClick(TObject *Sender)
{
 BPencil->Flat=false;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=1;
 RadioGroup1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BRectangleClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=false;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=2;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BEllepsClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=false;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=3;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BFillClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=false;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=4;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BEraserClick(TObject *Sender)
{
  BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=false;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=5;
 RadioGroup1->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BRectangleFillClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=false;
 BEllepsFill->Flat=true;
 BPipet->Flat=true;
 paint=6;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BEllepsFillClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=false;
 BPipet->Flat=true;
 paint=7;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BPipetClick(TObject *Sender)
{
 BPencil->Flat=true;
 BRectangle->Flat=true;
 BElleps->Flat=true;
 BFill->Flat=true;
 BEraser->Flat=true;
 BRectangleFill->Flat=true;
 BEllepsFill->Flat=true;
 BPipet->Flat=false;
 paint=8;
 RadioGroup1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CSpinEdit1Change(TObject *Sender)
{
     for(i=1;i<CSpinEdit1->Text.Length();i++)
         if(CSpinEdit1->Text[i]!='0' && CSpinEdit1->Text[i]!='1' &&
               CSpinEdit1->Text[i]!='2' && CSpinEdit1->Text[i]!='3' &&
               CSpinEdit1->Text[i]!='4' && CSpinEdit1->Text[i]!='5' &&
               CSpinEdit1->Text[i]!='6' && CSpinEdit1->Text[i]!='7' &&
               CSpinEdit1->Text[i]!='8' && CSpinEdit1->Text[i]!='9') {
            CSpinEdit1->Value=1;
            break;
         }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 value=CSpinEdit1->Value;
    switch(paint){
        case 1:              //pen
            MMove=true;
            if(Button==mbLeft){
                    BMouse=true;
                    Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
                    Image1->Canvas->Brush->Color=CColor1->Canvas->Brush->Color;
            }else if(Button==mbRight) {
                    BMouse=false;
                    Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
                    Image1->Canvas->Brush->Color=CColor2->Canvas->Brush->Color;
            }
            if(RadioGroup1->ItemIndex==0) {
                if(value>1)
    			    Image1->Canvas->Rectangle(X+value-1, Y+value-1, X-value+1, Y-value+1);
                else
		        	Image1->Canvas->Rectangle(X+value, Y+value, X-value, Y-value);
        	}else if(RadioGroup1->ItemIndex==1) {
	        	if(value>1)
        			Image1->Canvas->Ellipse(X+value-1, Y+value-1, X-value+1, Y-value+1);
    	    	else
	        		Image1->Canvas->Ellipse(X+value, Y+value, X-value, Y-value);
	        }else
	        	Image1->Canvas->LineTo(X,Y);
        break;
        case 2:case 3:case 6:case 7:  //eleps and rectagle, fillelleps and fillrectangle
            x=X; y=Y;
        break;
        case 5: //clean
            MMove=true;
            Image1->Canvas->Pen->Color=clWhite;
            Image1->Canvas->Brush->Color=clWhite;
            if(RadioGroup1->ItemIndex==0) {
                if(value>1)
    			    Image1->Canvas->Rectangle(X+value-1, Y+value-1, X-value+1, Y-value+1);
                else
		        	Image1->Canvas->Rectangle(X+value, Y+value, X-value, Y-value);
        	}else if(RadioGroup1->ItemIndex==1) {
	        	if(value>1)
        			Image1->Canvas->Ellipse(X+value-1, Y+value-1, X-value+1, Y-value+1);
    	    	else
	        		Image1->Canvas->Ellipse(X+value, Y+value, X-value, Y-value);
	        }else {
	        	Image1->Canvas->LineTo(X,Y);
            }
        break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
 if(MMove) {
  switch(paint){
        case 1:  //pen
                if(BMouse){
                    Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
                    Image1->Canvas->Brush->Color=CColor1->Canvas->Brush->Color;
                }else{
                    Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
                    Image1->Canvas->Brush->Color=CColor2->Canvas->Brush->Color;
                }
                if(RadioGroup1->ItemIndex==0) {
                    if(value>1)
                        Image1->Canvas->Rectangle(X+value-1, Y+value-1, X-value+1, Y-value+1);
                    else
                        Image1->Canvas->Rectangle(X+value, Y+value, X-value, Y-value);
                }else if(RadioGroup1->ItemIndex==1) {
                    if(value>1)
                        Image1->Canvas->Ellipse(X+value-1, Y+value-1, X-value+1, Y-value+1);
                    else
                        Image1->Canvas->Ellipse(X+value, Y+value, X-value, Y-value);
                }else
	        	    Image1->Canvas->LineTo(X,Y);
        break;
        case 5:  //clean
                Image1->Canvas->Pen->Color=clWhite;
                Image1->Canvas->Brush->Color=clWhite;
                if(RadioGroup1->ItemIndex==0) {
        		    if(value>1)
	        	    	Image1->Canvas->Rectangle(X+value-1, Y+value-1, X-value+1, Y-value+1);
        	    	else
	            		Image1->Canvas->Rectangle(X+value, Y+value, X-value, Y-value);
            	}else if(RadioGroup1->ItemIndex==1) {
            		if(value>1)
		            	Image1->Canvas->Ellipse(X+value-1, Y+value-1, X-value+1, Y-value+1);
            		else
            			Image1->Canvas->Ellipse(X+value, Y+value, X-value, Y-value);
            	}else
            		Image1->Canvas->LineTo(X,Y);
        break;
    }
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
 Image1->Canvas->Pen->Width=CSpinEdit1->Value;
    switch(paint){
        case 1: case 5:         //pen
            MMove=false;
        break;
        case 2:         //rectangle
            if(Button==mbLeft)
                Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
            else if(Button==mbRight)
                Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
            Image1->Canvas->Brush->Style=bsClear;
            Image1->Canvas->Rectangle(x,y,X,Y);
        break;
        case 3:         //elleps
            if(Button==mbLeft)
                Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
            else if(Button==mbRight)
                Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
            Image1->Canvas->Brush->Style=bsClear;
            Image1->Canvas->Ellipse(x,y,X,Y);
        break;
        case 4:
            if(Button==mbLeft) 
                Image1->Canvas->Brush->Color=CColor1->Canvas->Brush->Color;
            else if(Button==mbRight)
                Image1->Canvas->Brush->Color=CColor2->Canvas->Brush->Color;
            Image1->Canvas->FloodFill(X,Y,NULL,fsBorder);
        break;
        case 6:         //rectangle fill
            if(Button==mbLeft) {
                Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
                Image1->Canvas->Brush->Color=CColor2->Canvas->Brush->Color;
            }else if(Button==mbRight) {
                Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
                Image1->Canvas->Brush->Color=CColor1->Canvas->Brush->Color;
            }
            Image1->Canvas->Rectangle(x,y,X,Y);
        break;
        case 7:         //elleps fill
            if(Button==mbLeft) {
                Image1->Canvas->Pen->Color=CColor1->Canvas->Brush->Color;
                Image1->Canvas->Brush->Color=CColor2->Canvas->Brush->Color;
            }else if(Button==mbRight) {
                Image1->Canvas->Pen->Color=CColor2->Canvas->Brush->Color;
                Image1->Canvas->Brush->Color=CColor1->Canvas->Brush->Color;
            }
            Image1->Canvas->Ellipse(x,y,X,Y);
        break;
        case 8:
            if(Button==mbLeft) {
                CColor1->Canvas->Pen->Color=Image1->Canvas->Pixels[X][Y];
                CColor1->Canvas->Brush->Color=Image1->Canvas->Pixels[X][Y];
                CColor1->Canvas->FillRect(CColor1->ClientRect);
            }else if(Button==mbRight) {
                CColor2->Canvas->Pen->Color=Image1->Canvas->Pixels[X][Y];
                CColor2->Canvas->Brush->Color=Image1->Canvas->Pixels[X][Y];
                CColor2->Canvas->FillRect(CColor2->ClientRect);
            }
        break;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CColor1DblClick(TObject *Sender)
{
 if(ColorDialog1->Execute()) {
     CColor1->Canvas->Brush->Color=ColorDialog1->Color;
     CColor1->Canvas->FillRect(CColor1->ClientRect);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CColor2DblClick(TObject *Sender)
{
 if(ColorDialog1->Execute()) {
     CColor2->Canvas->Brush->Color=ColorDialog1->Color;
     CColor2->Canvas->FillRect(CColor2->ClientRect);
 }
}
//---------------------------------------------------------------------------


