#include<stdio.h>
int main(){
	int arr[100];
	int choice,n,pos,value,key,j,search_value,mid,start,end,index,sum,max,max_2,min,min_2,count,check,temp;
	int ar[100],l;
	do{
		printf("\tMENU\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra cac gia tri phan tu trong mang theo dang mang 1 chieu\n");
		printf("3. Dem so luong cac so hoan hao co trong mang\n");
		printf("4. Dem so luong so nguyen to\n");
		printf("5. Tim gia tri lon thu 2 trong mang, khong duoc sap xep mang\n");
		printf("6. Tim gia tri nho thu 2 trong mang, khong duoc sap xep mang\n");
		printf("7. Them mot phan tu vao vi tri ngau nhien trong  mang, phan tu moi them vao mang va vi tri them vao phai do nguoi dung nhap vao\n");
		printf("8. Xoa phan tu tai mot vi tri cu the(nguoi dung nhap vi tri xoa)\n");
		printf("9. Sap xep mang theo thu tu tang dan(Insertion sort)\n");
		printf("10. Sap xep mang theo thu tu giam dan(Insertion sort)\n");
		printf("11. Cho nguoi dung nhap vao mot phan tu, tim kiem xem phan tu do co ton tai trong mang hay khong(Binary search)\n");
		printf("12. Sap xep lai mang va hien thi ra toan bo phan tu co trong mang sao cho toan bo so chan dung truoc, so le dung sau\n");
		printf("13. Sap xep lai mang va hien thi ra toan bo phan tu co trong mang sao cho toan bo so le dung truoc, so chan dung sau\n");
		printf("14. Xoa phan tu trung lap va tim kiem phan tu doc nhat\n");
		printf("15. Dao nguoc thu tu cua cac phan tu co trong mang\n");
		printf("16. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d",&choice);
		switch (choice){
			case 1:
				printf("Nhap kich thuoc mang: ");
				scanf("%d",&n);
				printf("Nhap cac gia tri cho mang\n");
				for(int i = 0; i<n; i++){
					printf("arr[%d]=",i);
					scanf("%d",&arr[i]);
				}
				break;
			case 2:
				printf("Cac gia tri trong mang\n");
				for(int i = 0; i<n; i++){
					printf("arr[%d]= %d\n",i,arr[i]);
		        }
		        break;
		    case 3:
		    	index = 0;
		    	for(int i = 0; i<n; i++){
		    		sum = 0;
		    		for(int a = 1; a<arr[i]; a++){
		    			if(arr[i]%a==0){
		    				sum = sum+a;
						}
					}
					if(sum==arr[i]){
						index++;
					}
				}
				printf("Co %d so la so hoan hao",index);
				printf("\n");
		    	break;
		    case 4:
		    	count=0;
		    	for(int i = 0; i<n; i++){
		    		if(arr[i]<10){
		    			switch(arr[i]){
		    				case 2:
		    				case 3:
		    				case 5:
		    				case 7:
		    					count += 1;
						}
					}else if(arr[i]%2!=0&&arr[i]%3!=0&&arr[i]%5!=0&&arr[i]%7!=0){
						count += 1;
					}
				}
				printf("So luong so nguyen to trong mang la %d", count);
				printf("\n");
		    	break;
		    case 5:
		    	max = arr[0];
		    	for(int i = 0; i<n; i++){
		    		if(arr[i]>max){
		    			max_2=max;
		    			max=arr[i];
					}else if(arr[i]>max_2){
						max_2=arr[i];
					}
				}
				printf("So lon thu 2 trong mang la: %d",max_2);
				printf("\n");
		    	break;
		    case 6:
		    	min=arr[1];
		    	for(int i = 0; i<n; i++){
		    		if(arr[i]<min){
		    			min_2=min;
		    			min=arr[i];
					}else if(arr[i]<min_2){
						min_2=arr[i];
					}
				}
				printf("So nho thu 2 trong mang la: %d",min_2);
				printf("\n");
		    	break;
		    case 7:
		    	printf("Nhap vi tri muon them: ");
		    	scanf("%d",&pos);
		    	printf("Nhap gia tri muon them: ");
		    	scanf("%d",&value);
		    	if(pos < 0 || pos > n){
		    		printf("Vi tri khong hop le");
				}else{
					for(int i = n; i >= pos; i--){
						arr[i]=arr[i-1];
					}
				 arr[pos]=value;
			    }
				 n++;
		    	break;
		    case 8:
		    	printf("Nhap vi tri muon xoa: ");
		    	scanf("%d",&pos);
		    	if(pos < 0 || pos >= n){
		    		printf("Vi tri khong hop le");
				}else{
					for(int i = pos; i < n-1; i++){
						arr[i]=arr[1+i];
					}
				 n--;	
				}
		    	break;
		    case 9:
		    	for(int i = 0; i<n; i++){
		    		key=arr[i];
		    		j = i-1;
		    		for( j= i-1;j >= 0&&arr[j]>=key; j--){
		    		   arr[j+1]=arr[j];
					}
					arr[j+1]=key;
				}
				printf("Cac gia tri sau khi duoc sap xep: \n");
				for(int i = 0; i<n; i++){
					printf("arr[%d]= %d\n",i,arr[i]);
			    }
		    	break;
		    case 10:
		    	for(int i = 0; i<n; i++){
		    		key=arr[i];
		    		j = i-1;
		    		for( j= i-1;j >= 0&&arr[j]<=key; j--){
		    		   arr[j+1]=arr[j];
					}
					arr[j+1]=key;
				}
				printf("\n");
		    	break;
		    case 11:
		    	start = 0;
		    	end = n;
		    	printf("Nhap phan tu can tim: ");
		    	scanf("%d",&search_value);
		    	while(start<=end){
		    		mid = (start+end)/2;
		    		if(arr[mid]==search_value){
		    			break;
					}else if (arr[mid]>search_value){
						end = mid - 1;
					}else{
						start = mid + 1;
					}
			    }
			    if(arr[mid]==search_value){
			    	printf("Phan tu can tim nam o vi tri %d", mid	);
				}else{
					printf("Ko tim thay phan tu can tim");
				}
				printf("\n");
		    	break;
		    case 12:
		    	for(int i = 0; i<n; i++){
		    		for(int j = 0; j<n-i-1 ; j++){
		    			if((arr[j]%2>arr[j+1]%2) || (arr[j]%2==arr[j+1]%2 && arr[j]>arr[j+1])){
		    				temp=arr[j];
		    				arr[j]=arr[j+1];
		    				arr[j+1]=temp;
						}
					}
				}
				printf("Mang sau khi sap xep chan truoc , le sau\n");
				for(int i = 0; i<n; i++){
					printf("%d ",arr[i]);
				}
				printf("\n");
		    	break;
		    case 13:
		    		for(int i = 0; i<n; i++){
		    		for(int j = 0; j<n-i-1 ; j++){
		    			if((arr[j]%2<arr[j+1]%2) || (arr[j]%2==arr[j+1]%2 && arr[j]>arr[j+1])){
		    				temp=arr[j];
		    				arr[j]=arr[j+1];
		    				arr[j+1]=temp;
						}
					}
				}
				printf("Mang sau khi sap xep le truoc , chan sau\n");
				for(int i = 0; i<n; i++){
					printf("%d ",arr[i]);
				}
				printf("\n");
		    	break;
		    case 14:
		    	check=0;
		    	for(int i = 0; i<n; i++){
		    		check=0;
		    		for(int j = 0; j<l; j++){
		    			if(arr[i]==ar[j]){
		    				check=1;
		    				break;
						}
					}
					if(!check){
						ar[l++]=arr[i];
					}
				}
				for(int i = 0; i<l; i++){
					arr[i]=ar[i];
				}
				n=l;
				printf("Mang sau khi xoa phan tu trung lap\n");
				for(int i = 0; i<n; i++){
					printf("%d ",arr[i]);
				}
				printf("\n");
		    	break;
		    case 15:
		    	printf("Cac gia tri trong mang\n");
				for(int i = n-1; i>=0; i--){
					printf("arr[%d]= %d\n",i,arr[i]);
		        }
		    	break;
		    case 16:
		    	printf("Chuong trinh ket thuc");
		    	break;
		    	default:
		    	printf("Lua chon khong hop le\n");
	    }
    }while(choice!=11);
	return 0;
}
