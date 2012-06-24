import java.util.*;
import java.io.*;

public class DIV15 {
	public static void main(String[] args)throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String pati = br.readLine();
		int t=Integer.valueOf(pati);
		int site[]=new int[10];
		
		//array to hold the number of appearances
		
		while(t--!=0) {
			for(int i=0;i<10;i++) site[i]=0;
			
			String cif = br.readLine();
			char charcif[]=cif.toCharArray();
			int cifri[] = new int[charcif.length];
			int zbir=0;
			
			for(int i=0;i<charcif.length;i++) {
				cifri[i]=(int)charcif[i]-48;
				zbir+=cifri[i];   //SUM == zbir
				site[cifri[i]]++;// here i store them
			}
			
			if(site[0]>0 || site[5]>0) {
				//in case there is a 0 or a 5
				//else is immpossible
				if(zbir==0) {
					System.out.println("0");
					continue;
				}
				if(zbir%3==0) {
					//if the sum is divisible with 3
					if(site[0]>0) {
						Arrays.sort(cifri);
						for(int i=cifri.length-1;i>-1;i--) System.out.print(cifri[i]);
					}
					else {
						boolean ripni=true;
						Arrays.sort(cifri);
						
						for(int i=cifri.length-1;i>-1;i--) {
							if(ripni && cifri[i]==5) ripni=false;
							else System.out.print(cifri[i]);
						}
						System.out.print('5');
					}
					System.out.println("");
				}
				else {
					//System.out.println("where I suspect");
					int digit1=-1, digit2=-1, k;
					if(site[0]>0) k=0;
					else k=1;
					
					if((zbir-1)%3==0) {
						//if removing 1-2 digits will make the sum divisible with 3
						//when the sum is 3k+1 (1 4 7 10...)
						if(site[1]>0) {
							digit1=1;
							digit2=-1;
						}
						else if(site[4]>0) {
							digit1=4;
							digit2=-1;
						}
						else if(site[7]>0) {
							digit1=7;
							digit2=-1;
						}
						else if(site[2]>1) {
							digit1=2;
							digit2=2;
						}
						else if(site[2]>0 && site[5]>k) {
							digit1=2;
							digit2=5;
						}
						else if(site[5]>k+1) {
							digit1 = 5;
							digit2 = 5;
						}
						else if(site[2]>0 && site[8]>0) {
							digit1=2;
							digit2=8;
						}
						else if(site[5]>k && site[8]>0) {
							digit1=5;
							digit2=8;
						}
						else if(site[8]>1) {
							digit1=8;
							digit2=8;
						}
						else {
							System.out.println("impossible");
							continue;
						}
					}
					else if((zbir-2)%3==0) {
						//if removing 1-2 digits will make the sum divisible with 3
						//when the sum is 3k+2 (2 5 8 11...)
						
						if(site[2]>0) {
							digit1=2;
							digit2=-1;
						}
						else if(site[5]>k) {
							digit1=5;
							digit2=-1;
						}
						else if(site[8]>0) {
							digit1=8;
							digit2=-1;
						}
						else if(site[1]>1) {
							digit1=1;
							digit2=1;
						}
						else if(site[1]>0 && site[4]>0) {
							digit1=1;
							digit2=4;
						}
						else if(site[1]>0 && site[7]>0) {
							digit1=1;
							digit2=7;
						}
						else if(site[4]>1) {
							digit1=4;
							digit2=4;
						}
						else if(site[4]>0 && site[7]>0) {
							digit1=4;
							digit2=7;
						}
						else if(site[7]>1) {
							digit1=7;
							digit2=7;
						}
						else {
							System.out.println("impossible");
							continue;
						}
					}
					if(digit1>0 && digit2>0 && ((zbir-digit1-digit2)==0) && site[0]>0) {
						System.out.println("0");
					}
					else if(digit1>0 && ((zbir-digit1)==0) && site[0]>0) {
						System.out.println("0");
					}
					else if(site[0]>0) {
						Arrays.sort(cifri);
						for(int i=cifri.length-1;i>-1;i--) {
							if(cifri[i]==digit1) digit1=-1;
							else if(cifri[i]==digit2) digit2=-1;
							else System.out.print(cifri[i]);
						}
						System.out.println("");
					}
					else {
						int petka=5;
						Arrays.sort(cifri);
						for(int i=cifri.length-1;i>-1;i--) {
							if(cifri[i]==digit1) digit1=-1;
							else if(cifri[i]==petka) petka=-1;
							else if(cifri[i]==digit2) digit2=-1;
							else System.out.print(cifri[i]);
						}
						System.out.print('5');
						System.out.println("");
					}
				}
			}
			else System.out.println("impossible");
		}
	}
}

