#include "files.h"
	/**
	*creates file object
	**/
	
	Files::Files(){}

//argv stuff for user to input, checks if the files can be opened then returns the needed true or false
	/**
	* checks the argc and argv inputs and if they match the desired format, it also corrects the user if there are any mistakes
	*@param argc - input of main argc number of arguments 
	*@param argv - input of main argv name
	**/
	bool Files::Argvcheck(int argc,char const* argv[]){

		if (argc < NUM_ARGS) {
			std::cout << "\nCorrect Usage:" << std::endl;
			std::cout << argv[0] << " Directory" << std::endl<<std::endl;
			return 0;
    		}
		else{
			dir = opendir (argv[1]);

			if(dir){
				arg=1;
				return 1;
			}
			else{
				std::cout<<"\nCould Not Open Given Directory:"<<std::endl;
				std::cout<<argv[1]<<std::endl<<std::endl;
				return 0;
			}
		}
	}

	
//reads in all of the files so that we can change to read in the wav
	/**
	* lists all files
	*@param argv - input of main argv name
	**/
	
	void Files::Readfilenames(char const* argv[]){

		if(arg=1){

			while((read=readdir(dir)) != nullptr){

				filenames.emplace_back(read->d_name);
			}
			
			std::cout<<"\n~~Files~~"<<std::endl;
			for(std::string i:filenames){
				if( i != "." && i != ".."){
					std::cout<<i<<std::endl;
				}
			}
			std::cout<<std::endl;
		}
	}

	/**
	* gets the newfile name and also checks if the name is an appropriate .wav file and that no files with the same name exist
	**/
	
	std::string Files::getnewfile(){

		std::cout<<"\nWhat Would You Like to Name Your New File?"<<std::endl;
		std::cin>>newfile;

		if(wavcheck()){
			if(DupCheck()){
				return newfile;
			}
			else{
				std::cout<<"\nThis File Already Exists Please Enter A Different Name"<<std::endl;
			}
		}
		else{
			std::cout<<"\nCorrect Format:"<<std::endl;
			std::cout<<"filename.wav\n"<<std::endl;
		}
	}

	/**
	* check for if its a proper .wav
	**/
	
	bool Files::wavcheck(){

		int length=newfile.length();

		wav.push_back(newfile[length-4]);
		wav.push_back(newfile[length-3]);
		wav.push_back(newfile[length-2]);
		wav.push_back(newfile[length-1]);

		if(wav==".wav"){
			return 1;
		}
		else{
			return 0;
		}
		
	}
	
	/**
	* checks if the there are any files with the same name
	**/
	
	bool Files::DupCheck(){
	
		for(std::string i: filenames){
			if(newfile.compare(i) == 0){
				flag=1;
			}	
		}

		if(flag==1){
			return 0;
		}
		else{
			return 1;
		}
	}