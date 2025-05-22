
/*
	За да не обвързваме класа Application  с конкретна имплементация за писане във файл
	ще направим абстрактен базов клас fileWriter (ако искаме да можем да пишем и четем можем да добавим
	и методи за четене и да е например FileSerializer - това е практика за наименоване на класове
	които четат и пишат).
*/

class FileSerializer{
	std::string fileName;
	
	
	public:
	FileSerializer(const std::string & fileName):fileName(fileName){}
	
	
	virtual std::string read(char*data) const = 0;
	
	virtual void write(const char*data) =0;
};

class TXTFileSerializer:public FileSerializer{
	
	TXTFileSerializer(const std::string& fileName):FileSerializer(fileName){}
	
	std::string read (char*data)const override{
		std::string readData;
		std::ifstream ifs(fileName); // MUST open the streams in the constr and only read write here,
									//but i want it to be visible in the methods
		// ...
		
		return readData;
	}
	
	void write( const char*data)override{
		std::ofstream ofs(fileName); 
		//...
	}
}


class BinFileSerializer : public FileSerializer {
public:
    BinFileSerializer(const std::string& fileName) : FileSerializer(fileName) {}

    std::string read(char* data, std::size_t size) const override {
        std::ifstream ifs(fileName, std::ios::binary);
        //...
    }

    void write(const char* data) override {
        std::ofstream ofs(fileName, std::ios::binary);
        //...
    }
};

class Application{
	std::string data;
	FileSerializer* serializer
	
	public:
	
	Application(FileSerializer* serializer):
	serializer(serializer) // WE INJECT SERIALIZER INTO THE CLASS
	//
	// If you dont know why check : composition - aggregation 
	{}
	
	
	void writeData() {
        serializer->write(data.c_str());
    }

    void readData() {
        data = serializer->read();
    }

}

int main(){
	
TXTFileSerializer txtSerializer("example.txt");
    BinFileSerializer binSerializer("example.bin");

    // Inject them into Application (Application does not own them)
    Application appTxt(&txtSerializer);
    appTxt.writeData();
    appTxt.readData(100);

    Application appBin(&binSerializer);
    appBin.writeData();
    appBin.readData(100);

}
