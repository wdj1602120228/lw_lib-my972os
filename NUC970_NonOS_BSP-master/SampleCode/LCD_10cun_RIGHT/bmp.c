#include "bmp.h"
#include "drv_glcd.h"



//struct BMP_HEADER 	bmp_header;
struct BMP_INFO		bmp_info;





void Get_Bmp_Info(Int32U Bmp_add)
{
	Int8U i,len;
    pInt8U p =(pInt8U)Bmp_add;
	pInt8U pHead = (pInt8U)&bmp_info;
	// len=sizeof(struct BMP_HEADER);
	len=sizeof(struct BMP_INFO);
	for(i=0;i<len;i++)//54b
		{
			*pHead++ = *p++;
		}
	
	/**
	bmp_header.lBmp_Data_Offset		= *(p+13)<<24;
	bmp_header.lBmp_Data_Offset	   |= *(p+12)<<16;
	bmp_header.lBmp_Data_Offset	   |= *(p+11)<<8;
	bmp_header.lBmp_Data_Offset	   |= *(p+10);
	
	bmp_info.lBmp_Width				= *(p+21)<<24;
	bmp_info.lBmp_Width			   |= *(p+20)<<16;
	bmp_info.lBmp_Width			   |= *(p+19)<<8;
	bmp_info.lBmp_Width			   |= *(p+18);
	
	bmp_info.lBmp_Height			= *(p+25)<<24;
	bmp_info.lBmp_Height		   |= *(p+24)<<16;
	bmp_info.lBmp_Height		   |= *(p+23)<<8;
	bmp_info.lBmp_Height		   |= *(p+22);
	
	bmp_info.iBit_Count				= *(p+28);
	**/
	//Picwidth=bmp_info.lBmp_Width;//图片尺寸保存
	//Picheight=bmp_info.lBmp_Height;//
}

void Bmp_Decode(Int32U Bmp_add,Int16U StartX,Int16U StartY,pInt16U PicBase_RAM)
{
    Int8U color_byte;
	Int8U rgb = 0;
 //   Int8U count = 0;
    Int8U m = 0;
    Int16U byte1 = 0;
    Int8U byte2 = 0;
    Int8U byte3 = 0;
	Int16U color = 0;
    Int16U x = 0;
    Int16U y = 0;
	Int16U temp_col = 0;
	
	pInt16U pic_F;
	
	Get_Bmp_Info(Bmp_add);
	pic_F=PicBase_RAM+((bmp_info.lBmp_Height - 1 + StartY)*C_GLCD_H_SIZE + StartX);//第PicBase_RAM显示缓冲区
	
	
	// pInt8U cbmp =(pInt8U)(Bmp_add+bmp_header.lBmp_Data_Offset);
	pInt8U cbmp =(pInt8U)(Bmp_add+bmp_info.head.lBmp_Data_Offset);
	if(bmp_info.lBmp_Width>4)
       {
	    color_byte = bmp_info.iBit_Count>>3;
        m=(bmp_info.lBmp_Width*color_byte)%4;
        if(m>0)
        m=4-m;//宽度与4求余后的补数
       }
	while(1)
	   {	
		if(color_byte == 3)//24位颜色图
		  {   
		  switch ( rgb ) 
		     {
			 case 0 : //b
			    temp_col= *cbmp++ ;
                temp_col>>=3;                                          
    			color |= (temp_col&0x001f) ;
			       break ;			
			case 1 : //g
			    temp_col = *cbmp++ ;
                temp_col <<= 3 ;  
			    color |= (temp_col&0x07e0) ;
			       break ;
			case 2 : //r
			    temp_col = *cbmp++ ;
			    temp_col <<= 8 ;   
			    color |= (temp_col&0xf800);
			       break ;
		     }
		  rgb ++ ;
		  }
		else
		  {
			if(color_byte==2)//16位颜色图
			  {  
			    switch ( rgb )
			        {
				    case 0 : 
					    temp_col = *cbmp++ ;
				         break ; 
				    case 1 :    //高8位
				        color = *cbmp++ ;
				        color<<=8 ;
				        color |= temp_col ;
				        break ;
			        }
			    rgb++ ;
			  }
			else
			  {
				if(color_byte==4) //32位颜色图
				   {
					switch ( rgb )
				        {
						case 0 :  
						    byte1 = *cbmp++ ;	
							break ; 
						case 1 :  
						    byte2 = *cbmp++ ;
							break ;
						case 2 :  
						    byte3 = *cbmp++ ;
							break ;
						case 3 : 
                            cbmp++;
						    temp_col = byte1 >> 3 ;
					        color |= temp_col;
						    temp_col = byte2 >>2 ;
					        temp_col <<= 5 ;
					        color |= temp_col ;
							temp_col = byte3 >>3 ;
					        temp_col <<= 11 ;
					        color |= temp_col ;
							break ;
					    }
				    rgb ++ ;
				   }
				else
				   break;  //不是bmp文件
			  }   
		  }
//	    count ++ ;

/********* 速度较慢****
	   switch(color_byte)
		     {
		    case 2://16位颜色图
		         switch ( rgb )
			        {
				    case 0 : 
					    temp_col = *cbmp++ ;
				         break ; 
				    case 1 :    //高8位
				        color = *cbmp++ ;
				        color<<=8 ;
				        color |= temp_col ;
				        break ;
			        }
				                    break;
			case 3://24位颜色图
			     switch ( rgb ) 
		             {
			       case 0 : //b
			            temp_col= *cbmp++ ;
                        temp_col>>=3;                                          
    			         color |= (temp_col&0x001f) ;
			              break ;			
			       case 1 : //g
			            temp_col = *cbmp++ ;
                        temp_col <<= 3 ;  
			            color |= (temp_col&0x07e0) ;
			               break ;
			       case 2 : //r
			            temp_col = *cbmp++ ;
			            temp_col <<= 8 ;   
			            color |= (temp_col&0xf800);
			               break ;
		             }
			                        break ;
			case 4://32位颜色图	
			     switch ( rgb )
				      {
						case 0 :  
						    byte1 = *cbmp++ ;	
							  break ; 
						case 1 :  
						    byte2 = *cbmp++ ;
							  break ;
						case 2 :  
						    byte3 = *cbmp++ ;
							  break ;
						case 3 : 
                            cbmp++;
						    temp_col = byte1 >> 3 ;
					        color |= temp_col;
						    temp_col = byte2 >>2 ;
					        temp_col <<= 5 ;
					        color |= temp_col ;
							temp_col = byte3 >>3 ;
					        temp_col <<= 11 ;
					        color |= temp_col ;
							  break ;
					  }
					               break ;
		     }
		 rgb ++ ;
	*/		
	    if(rgb == color_byte)
		  {        //读取1像素数数据后显示
	        rgb = 0 ;
			
			*pic_F++=color;
			//PutPixel(x+GUICOMMAND.START_X,bmp_info.lBmp_Height - 1 - y + GUICOMMAND.START_Y, color);
			//PutPixel(x+StartX, bmp_info.lBmp_Height - 1 - y + StartY, color);
	        color = 0 ;
		    x++ ;
		    if(x >= bmp_info.lBmp_Width)
		       {
		        x = 0 ;
				cbmp += m;
		        y++ ;
			    if(y>=bmp_info.lBmp_Height)
			           break;
				   
		        pic_F=PicBase_RAM+((bmp_info.lBmp_Height - 1- y + StartY)*C_GLCD_H_SIZE + StartX);//第PicBase_RAM显示缓冲区
			   }
		  }
	   }
}
