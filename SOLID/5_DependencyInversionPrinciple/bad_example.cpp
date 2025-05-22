
class FileWritter{
	std::string fileName ;
	
	public:
	
	FileWritter(const std::string & fileName):fileName(fileName){
	}
	
	
	void write(const char*data){
		std::ofstream ofs( fileName );
		if(!ofs)
			return;
		
		ofs<< "File is txt";
		ofs.close();
	}
};


class Application{
	char* data;
	
	/*
		По този начин сме обвързали класа Application
		с fileWriter, който пък винаги пише в .txt файл и 
		ако искаме да имаме имплементация в която да пишем в двоичен файл
		или в .csv файл трябва да правим нови класове за всеки от тях ли???
	*/
	std::unique_ptr<FileWritter> fileWriter;
	
	Application (const char* fileName),fileWriter(std::make_unique<FileWritter> (fileName) ){}
	
	void writeData(){
		fileWriter.write(fileName,data); 
	}
	
	//copy constr, op= deleted
	
	~Application(){
		delete fileWriter;
	}
};