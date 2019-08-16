#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

#ifndef __DEBUG__
#define __DEBUG__
#endif //__DEBUG__

#ifndef __TMP_STORAGE__
#define __TMP_STORAGE__ "tmp.dat"
#endif

#ifndef __STORAGE_NAME__
#define __STORAGE_NAME__ "formulatrix.dat"
#endif

#ifndef __MAX_CONTENT_SIZE__
#define __MAX_CONTENT_SIZE__ 1000
#endif

#ifndef __MAX_NAME_SIZE__
#define __MAX_NAME_SIZE__ 100
#endif

using namespace std;

string readFile(ifstream& ifile, char *readBuffer, int size){

   for( int i=0; i < size; i++){
      ifile >> readBuffer[i];

      if( ifile.eof() )
         break; 
   }

   return readBuffer;
}

void writeFile(ofstream& ofile, char *writeBuffer, int size){

   for( int i=0; i < size; i++){
      ofile << writeBuffer[i];
   }
}

void saveItem(ofstream& ofile, string itemName, string itemContent, int itemType ){
  int lName = itemName.size();
  int lContent = itemContent.size();
  
  ofile.write( (char *) &itemType, sizeof(itemType));

  ofile.write( (char *) &lName, sizeof(lName));

  ofile << itemName;

  ofile.write( (char *) &lContent, sizeof(lContent));

  ofile << itemContent;
}

void storeItem( string itemName, string itemContent, int itemType ){
  ifstream ifile(__STORAGE_NAME__);

  if( !ifile){
    ofstream ofile(__STORAGE_NAME__);

    saveItem( ofile, itemName, itemContent, itemType);    
    ofile.close();
    
    return;
  }

  ifile.close(); 

  ofstream ofile(__STORAGE_NAME__, ios::app);

  saveItem( ofile, itemName, itemContent, itemType);    
  ofile.close();
}

string findName(ifstream& ifile, string sItemName, int lSItemName){
  int lItemName; 
  int lItemContent;
  int itemType;
  char itemName[__MAX_NAME_SIZE__];

  while( 1 ){

     #ifdef __DEBUG__
     cout << "pointer pos : " << ifile.tellg() << endl;
     #endif

     ifile.read( (char*) &itemType, sizeof(itemType));

     if( ifile.eof()){
        #ifdef __DEBUG__
        cout << "item : " << sItemName << " not found!" << endl;
        #endif   
        break;
     }
     #ifdef __DEBUG__
     else { cout << "read item type " << itemType << endl;}
     #endif

     #ifdef __DEBUG__
     cout << "read item name length" << endl;
     #endif

     ifile.read( (char*) &lItemName, sizeof(lItemName));
     if( lItemName != lSItemName ){
        #ifdef __DEBUG__
        cout << "item length " << lItemName << " is not match with " << lSItemName << endl;
        #endif

        ifile.seekg(lItemName, ios::cur);

        #ifdef __DEBUG__
        cout << "read item content length" << endl;
        #endif

        ifile.read( (char*) &lItemContent, sizeof(lItemContent));
        ifile.seekg(lItemContent, ios::cur);
        continue;
     }

     #ifdef __DEBUG__
     cout << "read item name" << endl;
     #endif

     ifile.read( itemName, lItemName);
     itemName[lItemName] = '\0';
     if( sItemName.compare( itemName) == 0){
         #ifdef __DEBUG__
         cout << sItemName << " is found!" << endl;
         #endif
         return sItemName;         
     }

     #ifdef __DEBUG__
     cout << "item : " << itemName << ", length : " << lItemName << endl;
     cout << "is not match with item " << sItemName << endl;
     #endif

     ifile.read( (char*) &lItemContent, sizeof(lItemContent));
     ifile.seekg(lItemContent, ios::cur); 
  }

  return "";
}

string retrieveContent(string sItemName){
  char content[__MAX_CONTENT_SIZE__];
  string itemContent;  
  ifstream ifile(__STORAGE_NAME__);
  int lContent;

  if(!ifile){
     return "";
  }

  if( (findName( ifile, sItemName, sItemName.size())).compare("") == 0 ){
     #ifdef __DEBUG__
     cout << "no content" << endl;
     #endif

     ifile.close();
     return "";
  }

  ifile.read( (char*) &lContent, sizeof(lContent));
  ifile.read( content, lContent);
  content[lContent] = '\0';  

  ifile.close();  

  return content;
}

int getItemType( string itemName){
  int itemType = 0;
  ifstream ifile(__STORAGE_NAME__);
  int itemNameSize = itemName.size();

  if( !ifile){ //if file does not exist
     return 0;
  }

  if( findName( ifile, itemName, itemNameSize).compare("") == 0){
     #ifdef __DEBUG__
     cout << "item is not found!" << endl;
     #endif

     ifile.close();
     return 0;
  }

  //item is found
  ifile.seekg( -itemNameSize, ios::cur);
  ifile.seekg( -sizeof(itemNameSize), ios::cur);
  ifile.seekg( -sizeof(itemType), ios::cur);

  ifile.read( (char*) &itemType, sizeof(itemType));
  
  ifile.close();
  return itemType;
}


void copyStorageFromTmp(){
   int itemType, lItemName, lItemContent;
   char sbuffer[__MAX_CONTENT_SIZE__];
   ifstream ifile(__TMP_STORAGE__);

   if( !ifile)
      return;

   ofstream ofile(__STORAGE_NAME__, ios::trunc);

   while(1){
     ifile.read((char*) &itemType, sizeof(itemType));
    
     if( ifile.eof())
        break;

     ofile.write((char*) &itemType, sizeof(itemType));

     ifile.read((char*) &lItemName, sizeof(lItemName));
     ifile.read((char*) sbuffer, lItemName);

     ofile.write((char*) &lItemName, sizeof(lItemName));
     ofile.write((char*) sbuffer, lItemName);

     ifile.read((char*) &lItemContent, sizeof(lItemContent));
     ifile.read((char*) sbuffer, lItemContent);     

     ofile.write((char*) &lItemContent, sizeof(lItemContent));
     ofile.write((char*) sbuffer, lItemContent);
   }

   ofile.close();
   ifile.close();

   //delete temporary storage
   //ofile.open( __TMP_STORAGE__, ios::trunc);
   //ofile.close();
}

void removeItem( string itemName){
  char sbuffer[__MAX_CONTENT_SIZE__];
  ifstream ifile(__STORAGE_NAME__);
  int itemType;
  int lItemName;
  int lItemContent;
  
  int itemNamePos;

  if( !ifile)
     return;

  if( findName( ifile, itemName, itemName.size()).compare("") == 0){
     #ifdef __DEBUG__
     cout << "item is not found!" << endl;
     #endif

     ifile.close();
     return;
  }

  //item is found
  lItemName = itemName.size();
  ifile.seekg( -lItemName, ios::cur);
  ifile.seekg( -sizeof(lItemName), ios::cur);
  ifile.seekg( -sizeof(itemType), ios::cur);

  itemNamePos = ifile.tellg();//current file pointer position
  
  //writing to temporary file
  ofstream ofile(__TMP_STORAGE__, ios::trunc);
  
  ifile.seekg(0);//reset pointer to beginning of file

  while(1){
     if( itemNamePos == ifile.tellg()){
         //skip
         ifile.read((char*) &itemType, sizeof(itemType));
         ifile.read((char*) &lItemName, sizeof(lItemName));
         ifile.seekg( lItemName, ios::cur);
         ifile.read((char*) &lItemContent, sizeof(lItemContent));
         ifile.seekg( lItemContent, ios::cur);
     }

     ifile.read((char*) &itemType, sizeof(itemType));
    
     if( ifile.eof())
        break;

     ofile.write((char*) &itemType, sizeof(itemType));

     ifile.read((char*) &lItemName, sizeof(lItemName));
     ifile.read((char*) sbuffer, lItemName);

     ofile.write((char*) &lItemName, sizeof(lItemName));
     ofile.write((char*) sbuffer, lItemName);

     ifile.read((char*) &lItemContent, sizeof(lItemContent));
     ifile.read((char*) sbuffer, lItemContent);     

     ofile.write((char*) &lItemContent, sizeof(lItemContent));
     ofile.write((char*) sbuffer, lItemContent);
  }
  
  ofile.close();

  ifile.close();

  copyStorageFromTmp();

  //delete temporary
  ofile.open(__TMP_STORAGE__, ios::trunc);
  ofile.close();
}

void Register( string itemName, string itemContent, int itemType ){
  #ifdef __DEBUG__
  cout << "Register" << endl;
  #endif
  
  storeItem( itemName, itemContent, itemType);
}

string Retrieve( string itemName ){
  #ifdef __DEBUG__
  cout << "Retrieve" << endl;
  #endif
  string content = retrieveContent( itemName);

  #ifdef __DEBUG__
  cout << "content : " << content << endl;
  #endif

  return content;
}

int GetType( string itemName ){
  #ifdef __DEBUG__
  cout << "GetType" << endl;
  #endif
  int itemType = getItemType( itemName);

  #ifdef __DEBUG__
  cout << "item type : " << itemType << endl;
  #endif

  return itemType;
}

void Deregister( string itemName ){
  #ifdef __DEBUG__
  cout << "Deregister" << endl;
  cout << itemName << endl;
  #endif

  removeItem( itemName);
}

int main(int argc, char **argv){

  if( argc < 2 ) return 1;

  if( strcmp(argv[1], "1")==0){
    if( strcmp(argv[4],"1") == 0){//cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << endl; 
       Register( (string) argv[2], (string) argv[3], 1);
    }else if( strcmp(argv[4],"2") == 0){//cout << argv[1] << " " << argv[2] << " " << argv[3] << " " << argv[4] << endl; 
       Register( (string) argv[2], (string) argv[3], 2);
    }
    #ifdef __DEBUG__
    else{
      cout << "wrong option " << argv[4] << endl; 
    }
    #endif
  }else if( strcmp(argv[1], "2")==0){
     Retrieve( argv[2]);
  }else if( strcmp(argv[1], "3")==0){
     GetType( argv[2]);
  }else if( strcmp(argv[1], "4")==0){
     Deregister( argv[2]);
  }
  #ifdef __DEBUG__
  else{
     cout << "wrong option" << endl;
  }
  #endif

  return 0;
}



