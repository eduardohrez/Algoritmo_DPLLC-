//created by Eduardo-H-R
//linkdin www.linkedin.com/in/eduardo-h-r
#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
using namespace std;

class algpdll
{
private:
    string stringehn, varpure, allvarb ,valortk, valoresparasat;
    int numsize=0;
public:
    algpdll(string decalrest); //obtener la  formula proposicional normal conjuntiva
    void allval_alg(int regres);
    void genallbarb(int sizestr);
    void printvar();
    int genval(int nustr,string evalstr);
    void algpurev();
    void genblank();
    void blank_erase(int numstring, int cont);
    ////////////////////
    bool algdlpll(string value ,string alllvalues,string areatake, bool *valfc);
    int countvalt(string *allval);
    string selectval( string *valselc);
    string tkval(string *allval,int valalt);
    string staralg();
    string processtrvar(string func, string value);
    bool eraze_post(string *allstr, string *val);
    bool eraze_neg(string *allstr, string *val);
    bool verfvaln(string *valneg,int place);
    void delatevalue(string *valstr, string dellvar);
    bool verefallsrt(string verval, string valref);
    void delvasal(string *ultvalde);
    void fillval(string addval);
    string gen_llproces();

    void prueb();

    ~algpdll();
};
algpdll::algpdll(string decalrest)
{
    stringehn=decalrest;
    //cout<<decalrest.size()<< "---"<<lengstr<<endl;
    numsize=decalrest.size();
    //cout<<"the string include is %% "<<stringehn <<" %%"<<endl;
}

// star to clean and prapare the string 

string algpdll::gen_llproces()//iniciar todo el proceso para obtener la solucion de 
{
    string values_sat;
    genblank();
    allval_alg(0);
    algpurev();
    values_sat=staralg();
    return values_sat;

}

void algpdll::allval_alg(int regres) //generar todas las variables de la formula 
{
    //cout<<stringehn.substr(0,2)<<endl;
    int valstring=0, valarrg=0;
    allvarb +=",";
    for (size_t i = 0; i < stringehn.size(); i++) 
    { 
        if( stringehn[i]!='|' && stringehn[i]!='(' && stringehn[i]!=')' && stringehn[i]!='&' &&stringehn[i]!='~' &&allvarb.find(stringehn.substr(i,genval(i,stringehn)),0)>allvarb.size() )
        {
            //allvarb.find(stringehn.substr(genval(i),0)) >allvarb.size()
            //cout<<allvarb.find(stringehn.substr(i,genval(i)),0)<<" " <<allvarb.size() <<endl;// verf if alredi exist value on allvarb construct below
            
            //cout<<stringehn.substr(i,genval(i))<<endl;
            
            allvarb.append(stringehn,i,genval(i,stringehn));
            allvarb +=",";
            i=i+genval(i,stringehn);
            }  
    }
    cout<<"the all varb are = "<<allvarb<<endl;
}

void algpdll::printvar() //imprimir toda la formula
{
    cout<<stringehn<<endl;
}

void algpdll::genblank() // funcion para iniciar la funcion recursiva para blank_erase
{

    blank_erase(stringehn.size(),0);
    cout<<stringehn<<endl;
}

void algpdll::blank_erase(int numstring,int cont) //funcion recursiva de borrado para zonas vacias de la formula introducida
{
    if(cont>= numstring)
    {
        return;
    }
    if(stringehn[cont]==' ')
    {
        stringehn.erase(stringehn.begin()+ cont);
        blank_erase(stringehn.size(),cont);    
    }
    else
    {
        blank_erase(numstring,cont+1);
    }
     
}

int algpdll::genval(int nustr, string evalstr)// obtener cuantos valores estan antes de los strings puestos en el while y retornar el valor usado en la funcion algpure 
{
    int valcont=0;
    while(evalstr[nustr]!= '|' &&evalstr[nustr]!= '(' &&evalstr[nustr]!= ')' &&evalstr[nustr]!= '&' &&evalstr[nustr]!= ',' )
    {
        nustr++;
        valcont++;
    }
    return valcont;
   
}

void algpdll::algpurev() // funcion para obtener las variables que son puras (variables que solo son negadas o solo son positivas)
{
size_t valinc=0;
// valinc= stringehn.find("A",valinc+1);
// cout<<valinc<<endl;
// valinc= stringehn.find("A",valinc+1);
// cout<<valinc<<endl;
valinc=0;
bool valneg=false,valps=false;
int valstrneg=0, valstr=0 ,valuestr=0;
size_t strgen=stringehn.size();
varpure+=",";       
for (size_t i = 0; i < allvarb.size(); i++)
{
    if(allvarb[i-1] ==',')
    {
    valstr=genval(i,allvarb);
    //cout<<valstr<<endl;
    // cout<<stringehn.find("~" +allvarb.substr(i,valstr))<<"---"<<allvarb.substr(i,valstr);
    // cout<<"---"<<stringehn.find(allvarb.substr(i,valstr))<<"--"<<allvarb.substr(i,valstr);
    while (valstrneg<strgen || valuestr<strgen )
    {
        if(valuestr<strgen && valuestr >-1) valuestr= stringehn.find( allvarb.substr(i,valstr),valuestr+1); 
        if(valstrneg<strgen) valstrneg=stringehn.find("~" +allvarb.substr(i,valstr),valstrneg+1); 
        
        if(valuestr <strgen && stringehn[valuestr-1]!='~' )
        {
            valps=true;
            //cout<<"valpos ";
        }
        if(valstrneg<strgen )
        {
            valneg=true;
            //cout<<"--valneg";
        }

        if(valstrneg<0 || valstrneg>strgen) valstrneg=strgen;
        if(valuestr<0 || valstrneg>strgen) valuestr=strgen;        
        //cout<<valuestr<<"||"<<valstrneg <<endl;
    }
    if(valneg== true && valps==false)
    {
        //cout<<"valpos"<<endl;
        varpure+= "~";
        varpure.append(allvarb,i,valstr);
        varpure+=",";
    }
    if(valps==true && valneg==false)
    {
        //cout<<"into val"<<endl;
        varpure.append(allvarb,i,valstr);
        varpure+=",";
    }
    valuestr=0;
    valstrneg=0;
    valps=false;
    valneg=false;
    }  
}
cout<<"the all pure values"<<varpure<<endl;   
}
//end of procesing data and start whit algorithm

int algpdll::countvalt(string *allval) //conteo de todas las variables se usa en selectval
{
    //cout<<allval->at(0)<<endl;
    int cont_com=0,i=0;
    string tkdat;
    //cout<< allval->size()<<endl;
    while (allval->find(',',i)<= allval->size())
    {

        
        if(allval->find(',',i)<= allval->size())
        {
            cont_com++;
            i=allval->find(',',i);
            i=i+1;
        }   
    }
 //cout<<cont_com-1<<endl;
 return cont_com;   
}
string algpdll::tkval(string *allval,int valalt)//retornar el string del numero de la variable tomado 
{
    int cont=0,i=0,b=0;
    string tkvalalt;
    while (cont<= valalt-1)
    {
        if(allval->find(',',i)<= allval->size())
        {
            if(cont== valalt-1)
            {
                b=(allval->find(',',i+1));
                //cout<<b<<endl;
                if(i==0) tkvalalt=allval->substr(allval->find(',',i)+1 ,(b-(allval->find(',',i)+1)));
                else tkvalalt=allval->substr(allval->find(',',i)+1 ,(allval->find(',',b+1))-(allval->find(',',i)+1));
                // cout<<"into val"<<endl;
               // cout<<i<<" "<<b-(allval->find(',',i)+1)<<endl;
                // cout<<allval->at(allval->find(',',i)+1 )<<endl;
            }

            cont++;
            i=allval->find(',',i);
            i++;
        }

    }
    //cout<<tkvalalt<<endl;
    return tkvalalt;
}

string algpdll::selectval( string *valselc) //seleccionar una variable aleaotria
{
    srand(time(NULL));
    int val_elemt=0,numrand;
    string selcted_st;
    val_elemt=countvalt(valselc);
    //cout<<val_elemt<<endl;
    numrand =  1+rand() % (val_elemt - 1);
    //cout<<numrand<<endl;
    selcted_st=tkval(valselc,numrand);
    cout<<selcted_st<<endl;
    return selcted_st;
}

///////////////////////////////////////
bool algpdll::verfvaln(string *valneg, int place)//verificar si la variables es negada o no lo es
{
    // cout<<endl;
    // cout<<valneg->at(place-1)<<endl;
    if(valneg->at(place-1)=='~')
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


bool algpdll::eraze_post(string *allstr,string *val) //borrar en la formula enviada el valor enviado borrar toda una preposicion si es positiva 
{
    int cont=0,numclos=0, endpost=0, numsubsrt=0;
    bool valneg=true,retuncar=false;
    string substr;
    //cout<<*val<<endl;
    while (cont<allstr->size())
    {
        if(allstr->at(cont)=='(')
        {
            //cout<< allstr->substr(cont,allstr->find(')',cont)-cont+1)<<" ";
            substr=allstr->substr(cont,allstr->find(')',cont)-cont+1);
            numsubsrt=allstr->find(')',cont);
            if(substr.find(*val)<substr.size())
            {
                //cout<<"-----"<<"have val";
                valneg=verfvaln(&substr,substr.find(*val));
                //cout<< "------- val ---"<< valneg<<"------"<<endl;
                
                if(valneg ==true)
                {
                    //cout<<substr.find('~'+*val)<<" "<<allstr->substr(cont+substr.find('~'+*val),val->size()+1)<<" "<< allstr->at(cont+substr.find('~'+*val)-1)<<endl;
                    //allstr->at(cont+substr.find('~'+*val)-1);
                    if (allstr->at(cont+substr.find('~'+*val)-1) == '(' && allstr->at(cont+(substr.find('~'+*val))+(val->size()+1))== ')')
                    {
                        //cout<<"--------------------------------the var alone--------------------";
                        retuncar= true;
                        return true;
                    }                    
                    else if( allstr->at(cont+substr.find('~'+*val)-1) != '(')
                    {
                    //cout<<"------"<<allstr->substr(cont+substr.find('~'+*val)-1,val->size()+2)<<endl;
                    allstr->erase(cont+substr.find('~'+*val)-1,val->size()+2);
                    //cout<<*allstr<<endl;
                    cont++;
                    }
                    else 
                    {
                        //cout<<"into )"<<endl;  
                        allstr->erase(cont+substr.find('~'+*val),val->size()+2);
                        //cout<<*allstr<<endl;
                        cont++;
                    }  
                }
                else
                {
                    //cout<<"error "<< allstr->size()+1<<cont  <<"...." <<allstr->find(')',cont)<< "##"<<allstr->size()  <<endl;
                    if(cont==0 && allstr->find(')',cont)+1==allstr->size() )
                    {
                        allstr->erase(cont,allstr->size());
                        cout<<allstr<<endl;
                    }

                    else if(allstr->size()+1==cont+substr.size()+1) allstr->erase(cont-1,substr.size()+1);
                    //cout<<allstr->size()<<" "<<cont+substr.size()+1<<endl;
                    
                    else allstr->erase(cont,substr.size()+1);
                    //cout<<" val ant"<<"----"<<cont;
                    
                    cont=cont-substr.size();
                    //cout<<"vaaal"<<allstr->substr(cont,substr.size())<<endl;
                    //cout<<"the cout "<<cont<<endl;
                    if(cont<0)
                    {
                        cont=0;
                    }
                    //cout<<*allstr<<endl;
                }
                
            }
            else
            {
                //cout<<endl;
                cont++;
            }
            // cout<<allstr->find(')',cont+1)<<endl;
            // endpost=allstr->find(')',cont+1);
            // substr= allstr->substr(cont,endpost);
            // cout<<substr<<endl;
        }
        else
        {
        cont++;
        }
        
    }
    //cout<<*allstr<<endl;
    return retuncar;
}
bool algpdll::eraze_neg(string *allstr, string *val) //borrar en la formula enviada el valor enviado borrar toda una preposicion si es negativa
{

    int cont=0,numclos=0, endpost=0, numsubsrt=0;
    bool valneg=false, retcar=false;
    string substr;
    //*val="x1";
    //cout<<*val<<endl;
    while (cont<allstr->size())
    {
        if(allstr->at(cont)=='(')
        {
             
            //cout<< allstr->substr(cont,allstr->find(')',cont)-cont+1)<<" ";
            substr=allstr->substr(cont,allstr->find(')',cont)-cont+1);
            numsubsrt=allstr->find(')',cont);
            
            if(substr.find(*val)<substr.size())
            {
                
                //cout<<"-----"<<"have val";
                
                valneg=verfvaln(&substr,substr.find(*val));
                
                //cout<< "------- val ---"<< valneg<<"------"<<endl;

                if(valneg ==true)
                {     
                                
                    //cout<<allstr->find(')',cont)<<"        "<<allstr->size()<<"------"<<allstr->substr(cont,substr.size())<<endl;
                    if(allstr->find(')',cont+1)+1 == allstr->size())
                    {
                    cout<<"into val asdasd  "<<*val<<"...."<<*allstr<<"..."<<cont<<endl;
                    if(cont==0)
                    {
                        allstr->erase(cont,substr.size()+1); 
                    }
                    else
                    {
                        allstr->erase(cont-1,substr.size()+1);     
                    }
                    }
                    else allstr->erase(cont,substr.size()+1);
                    cont=cont-substr.size();
                    if(cont<0) cont=0;
                    //cout<<*allstr<<endl;
                    //cont++;                
                }
                else
                {
                    //cout<<substr<<"---"<<substr.find(*val)<<"---------"<<allstr->substr(cont+substr.find(*val),val->size()+1) <<endl;
                    // if(allstr->size()+1==cont+substr.size()+1) allstr->erase(cont-1,substr.size()+1);
                    //cout<<"--------" <<allstr->at(cont+substr.find(*val)+1)<<endl;
                    //cout<<"&&&&&&&&"<< allstr->at(cont+substr.find(*val)+val->size())<<endl;
                    if (allstr->at(cont+substr.find(*val)-1) =='(' && allstr->at(cont+substr.find(*val)+val->size()) == ')')
                    {
                        retcar= true;
                        cout<<"in to vaal"<<endl;
                        return true;
                    }
                    else if(allstr->at(cont+substr.find(*val)-1) =='(' )
                    {
                        //cout<<allstr->substr(cont+substr.find(*val),val->size()+1)<<endl;
                        allstr->erase(cont+substr.find(*val),val->size()+1);
                    }
                    else if (allstr->at(cont+substr.find(*val)+val->size()) == ')')
                    {
                        allstr->erase(cont+substr.find(*val)-1,val->size()+1);
                    }
                    else
                    {
                        allstr->erase(cont+substr.find(*val),val->size()+1);

                    }
                    
                    //cout<<*allstr<<endl;
                    cont++;
                }  
            }
            else
            {
                //cout<<endl;
                cont++;
            }
        }
        else
        {
        cont++;
        }
        
    }
    return retcar; 
}

void algpdll::delatevalue(string *valstr, string dellvar) //eliminar la varible en el string que se envia con las varibles que exiten
{
 int numval=0;
 numval=valstr->find(dellvar);

 if(numval-1==0)
 {
     valstr->erase(0,dellvar.size()+1);
 }
 else if (numval+1==valstr->size())
 {
     valstr->erase(numval-1, dellvar.size()+1);
 }
 else
 {
     valstr->erase(numval,dellvar.size()+1);
 }
 cout<<dellvar<<"------"<<*valstr<<endl;

 
}

void algpdll::prueb() //prueba se usar para probar las diferentes funciones
{
     string examp= "", vald="~1";
    // cout<<examp<<endl;
    // cout<<eraze_neg(&examp,&vald)<<"++++";
    // cout<<examp<<"**********"<<endl;
    //delvasal(&vald);

    fillval(vald);

    cout<<valoresparasat<<endl;
    fillval("1");

    cout<<valoresparasat<<endl;
        fillval("~1");

    cout<<valoresparasat<<endl;
}


string algpdll::staralg() //iniciar el algoritmo recursivo de la funcion depll
{
    string valttak,mandvalue ,allevalstr=stringehn;
    valttak=allvarb;
    bool valrf=true;
    int valregres=1;
    regresar:
    mandvalue=selectval(&valttak);
    delatevalue(&valttak,mandvalue);
    //cout<<valttak.size()<<endl;
    //cout<<mandvalue<<"------"<<valttak<<"---"<<allevalstr<<endl;
    valregres=algdlpll(mandvalue,allvarb,allevalstr,&valrf);
    cout<<"######" <<valregres<<"###" <<valrf <<endl;
    if(valttak.size() > 1 && valrf==false)
    {   cout<<"~~~~~~~~~~~~~~~~into algv~~~~~~~~~~~~~~"<<valoresparasat   ;
        valoresparasat.erase(0,valoresparasat.size());
        cout<<".............."<< "the val "<<valoresparasat<<endl;
        goto regresar;
    }
    if(valrf== true)
    {
        //valoresparasat+=mandvalue;
        cout<<"satisfase la formula y los valores para la satisfaccion son los siguientes  "<< valoresparasat  <<endl;
        return(valoresparasat);
    }
    if (valrf== false)
    {
        cout<<"no se satisfase no ay solucion"<<endl;
        return("empty");
    }
    //cout<<algdlpll(allvarb,stringehn)<<endl;
}

bool algpdll::verefallsrt(string verval,string valref) //verificar en el string enviado el valor enviado si existen valores negativos y positivos de el 
{
    bool varet=false,varetn=false;
    cout<<verval<<endl;
    for (int i = 0; i < verval.size(); i++)
    {
        //verval.at(verval.find(valref,i)-1)
        if(verval.find(valref,i)< verval.size() )
        {
            if(verval.at(verval.find(valref,i)-1) == '~')
            {varet=true;
            i=i+verval.find(valref,i);
            //cout<<"into true"<<endl;
            }
            else
            {
                //cout<<"into false"<<endl;
                varetn=true;
                i=i+verval.find(valref,i);
            }

        }
        // else
        // {
        //     //cout<<"into false"<<endl;
        //     varetn=true;
        // }
        
    }

    cout<<varet<<" "<<varetn<<endl;
    if(varetn== true && varet==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void algpdll::delvasal(string *ultvalde) //no se usa
{
    
    bool valreg= false;
    int val= ultvalde->size()-1;
    if(val>2)
    { 
    while(valreg== false)
    {
        //cout<<ultvalde->at(val-1)<<endl;
        if( ultvalde->at(val)==',')
        {
            ultvalde->erase(val,ultvalde->size()-val);
            valreg=true;
        }
    val--;
    }
    
    }
}
void algpdll::fillval(string addval) //llena de las variables las cuales satifasen la formula 
{
    string valn;
    if(addval.at(0)=='~')
    {
        valn=addval.substr(1,addval.size()+1);
        if(valoresparasat.find(valn)< valoresparasat.size() &&  valoresparasat.find(addval)>valoresparasat.size())
        {
            valoresparasat.insert(valoresparasat.find(valn),"~");
        }
        else if (valoresparasat.find(valn)>valoresparasat.size() &&  valoresparasat.find(addval)>valoresparasat.size())
        {
            valoresparasat+=","+addval;
        }
        
    }
    else
    {
        if(valoresparasat.find(addval)>valoresparasat.size())
        {
            valoresparasat+=","+addval;
        }
        else if(valoresparasat.find(addval)<valoresparasat.size() &&  valoresparasat.at(valoresparasat.find(addval)-1) =='~' )
        {
            valoresparasat.erase(valoresparasat.find(addval)-1,1);
        }
    }
    

}




bool algpdll::algdlpll(string value ,string alllvalues,string areatake,bool *valfc) // algoritmo recursivo que realiza el proceso de selecciones y eliminacion de las varibales
{
    //cout<<value<<"------"<<alllvalues<<"---"<<areatake<<endl;
    string valttak,allevalstr=alllvalues, fullval=areatake;
    bool defval=true, intoneg=false;
    valttak=alllvalues;
    
        if(value.size()+2==alllvalues.size() || areatake.size()<1)
    {

        cout<<areatake.find('~'+value)<<"...."<<areatake.find(value)<<"....."<<value<< " " <<areatake.size()<<"...."<<areatake+"...";
        if( verefallsrt(areatake,value) )
        {
            cout<<"  intoo"<<endl;
            *valfc=false;
            return 0;
        }
        else
        {
            string valdar;
            //cout<<areatake.substr(areatake.find('(')+1,areatake.find(')')-areatake.find('('))<<endl;
            valdar=areatake.substr(areatake.find('(')+1,areatake.find(')')-areatake.find('(')-1);
            cout<<valdar<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
            if(valdar.size()>0) fillval(valdar);
            if(areatake.find(value)>areatake.size()) fillval(value);
            *valfc= true;
            return 1;
        }
    }
    
    // bool valrf=true;
    // int valregres=1;
    againstart:

    bool val1=true;
    string valant=areatake;
    cout<<"ini alg"<<areatake<<"...."<<value<< endl;
    val1=eraze_post(&areatake,&value); 
    //cout<<areatake<<" "<<  val1 <<"^^^^^^^^^^"<<verefallsrt(areatake,value) <<"^^^^^^^"<<value<<endl;
    //val1=verefallsrt(areatake,value);
    /////////////////////////////////////////////////////////////////
    if(val1==true)
    {
        valneg:
        areatake=valant;
        val1=eraze_neg(&areatake,&value);
        intoneg=true;
        if (val1==true)
        {
            cout<<"in to vaaaaal"<<endl;

            *valfc= false;
            return 0;
        }
        else
        {
            //contad++;
            //valoresparasat+=",~"+ value;
            fillval("~"+value);
            goto initval;
        }   
    }
    else
    {
        //contad++;
        fillval(value);
        //valoresparasat+=","+ value;
        initval:
        cout<<"#####"<<value<<"-----";
        
        cout<<"////"<<areatake<< value<<endl;
        delatevalue(&alllvalues,value);
        value=selectval(&alllvalues);
        cout<<alllvalues<<"--"<<alllvalues.size()<<"// "<< value.size()<<"/// "<< areatake<<endl;
        defval= algdlpll(value,alllvalues,areatake,valfc);
        cout<<"finish  "<< allevalstr.size()<<"  " <<allevalstr <<"  " << value<<endl;

        if(allevalstr.size()-value.size() > 2 && *valfc==false && allevalstr.size()>2)
        {
            //valoresparasat.erase(0,valoresparasat.size());
            // cout<<"|||||||||||"<<valoresparasat<<endl;
            // delvasal(&valoresparasat);
            //cout<<"|||||||||||"<<valoresparasat<<"---"<<contad-1 <<  endl;
            //valoresparasat.erase(0,valoresparasat.size());
            areatake=fullval;
            //contad=0;
            alllvalues=valttak;
            cout<<"return to vall  "<<value<< "  +++++++ "<<allevalstr<<endl;
            //delatevalue(&allevalstr,value);
            //cout<<"return to vall  "<<value<< "+++++++ "<<allevalstr<<endl; 
            value=selectval(&allevalstr);
            
            delatevalue(&allevalstr,value);
            cout<<"return to vall"<<value<<endl;

        goto againstart;
        }
        else
        {
            return defval;
        }
        

    }
}



algpdll::~algpdll() // 
{
}
