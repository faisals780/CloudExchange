#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <list>
#include <iomanip>
#include <sstream>

class User{
    private:
    std::string userID;
    std::string email;
    std::string name;
    int age;

    public:
    User(const std::string userID,const std::string name, const  std::string email,const  int age) : userID(userID) ,name(name), email(email) , age(age){}

    std::string getUserID(){return userID;}
    std::string getName(){return name;}
    std::string getEmail(){return email;}
    int getAge(){return age;}

    virtual std::string getUserType() = 0;

    virtual ~User() = default;
};

class Transactable{
    public:

    virtual std::string addTransactions(std::string txnId) = 0;
    virtual const std::vector<std::string>& getTransactions()=  0;

    virtual ~Transactable() = default;
};

class Buyer : public User , public Transactable{
    private:
    std::string shippingAddress;
    std::vector<std::string> transactions;

    public:
    Buyer(std::string userID,std::string name, std::string email, int age, std::string shippingAddress) : User(userID,name, email, age) , shippingAddress(shippingAddress){}

    std::string getUserType()override{return "Buyer";}
    
    std::string addTransactions(std::string txnId)override{
        transactions.push_back(txnId);

        return ("Transaction recorded: " + txnId + "\n");
    }

    const std::vector<std::string>& getTransactions()override{
        return transactions;
    }

    std::string getShippingAddress()const{return shippingAddress;};
};

class Seller : public User{
    private:
    std::string storeName;
    std::unordered_set<std::string> productCategory;

    public:
    Seller(std::string userId,std::string name, std::string email, int age, std::string storeName) : User(userId, name, email, age) , storeName(storeName){}

    std::string getUserType()override{return "Seller";}
    std::string getStoreName()const{return storeName;}

    void addCategory(std::string category){
        productCategory.insert(category);
    }

    const std::unordered_set<std::string>& getCategories(){

        return productCategory;
    }
};

class Product{
    private:
    std::string productId;
    std::string productName;
    double price;
    Seller* vendor;

    public:
    Product(const std::string productId,const std::string productName, Seller* vendor , double price) : productId(productId) , productName(productName) , vendor(vendor), price(price){} 

    std::string getProductId()const{return productId;}
    std::string getProductName()const{return productName;}
    double getPrice()const{return price;}

    std::string getProductDetail(){

        std::ostringstream productDetail;
        std::ostringstream temp;
        temp << std::fixed << std::setprecision(2) << price;

        productDetail << "\n----- Product Detail ----\n";

        productDetail << "Product ID: " << std::setw(10) << std::left << productId << "Product name: " << std::setw(15) << std::left << productName << "Price: " << std::setw(10) << std::left << temp.str() << "Seller's store name: " << vendor->getStoreName() << "\n";

        return productDetail.str();
    }
};

class Order {
    private:
    std::string orderId;
    Buyer* client;
    std::list<Product*> items;
    std::string status;

    public:
    Order(const std::string orderId, Buyer* client) : orderId(orderId) , client(client), status("Pending"){}

    void addProduct(Product* p){
        items.push_back(p); 
    }

    double getOrderTotal()const{
        double total = 0;
        for(const auto& ptr: items){
            total += ptr->getPrice();
        }
        return total;
    }
    void updateStatus(std::string status){
        this->status = status;
    }

    std::string getOrderDetail(){
        std::ostringstream detail;

        detail << "\n---- Order Detail ----\n";
        detail << "Order ID: " << std::setw(10) << std::left << orderId ;
        detail << "Buyer name: " << std::setw(15) << std::left << client->getName() ;
        detail << "Status: " << std::setw(8) << std::left << status << "\n";
        detail << "All Product: " ;
        for(const auto& ptr: items){
            detail << ptr->getProductName() << ", ";
        }
        detail << "Total amount: " << getOrderTotal() << "\n" ;

        return detail.str();
    }

};

class Platform{
    private:
    std::string platformName;
    std::vector<Buyer*> buyerPerson;
    std::vector<Seller*> sellerPerson;
    std::vector<Order*> order;

    public:

    Platform(std::string platformName): platformName(platformName){}

    void addBuyer(Buyer* b){
        buyerPerson.push_back(b);
    }

    void addSeller(Seller* s){
        sellerPerson.push_back(s);
    }

    void addOrder(Order* o){
        order.push_back(o);
    }

    std::string getPlatformReport(){
        std::ostringstream report;

        report << "\n------ Detail Report of "<< platformName << " ------\n";

        report << "All Buyer Detail:\n";

        int count = 0;
        for(const auto& ptr: buyerPerson){
            report <<++count << ": "<< "Order ID:" << std::setw(10) << std::left << ptr->getUserID() << " | " << "Name: " << std::setw(15) << std::left << ptr->getName() << "Email: " << std::setw(20) << std::left << ptr->getEmail() << " | " << "Shipping address: " << std::setw(20) << std::left << ptr->getShippingAddress() << "\n";
           
            report << "----- All Transactions -----\n";

            if(ptr->getTransactions().empty()){
                report << "No transaction found ! \n";
            }else{
                for(const auto& pptr: ptr->getTransactions()){
    
                    report <<"   - " <<  pptr << "\n" ;
                }
            }
            report << "-----------------------------------------\n";
        }
        report << "\n--- All Orders Details ---\n";
        for (const auto& oPtr : order) {
            report << oPtr->getOrderDetail();
        }

        return report.str();
    }

};

int main(){

    Platform onlineStore("Amazon");

    Seller* s = new Seller("A34D93","Arhan Alam", "arhaan123@gmail.com", 30, "Arhaan Digi Store");
    Seller* s1 = new Seller("B12W35","Kasif", "kasifWorld@yahoo.com", 23, "Kasif Smart World");
    
    s->addCategory("Home appliances");
    s->addCategory("Mobile");
    s->addCategory("Kids");
    
    s1->addCategory("Appreal");
    s1->addCategory("Leather");
    s1->addCategory("Shoes");

    onlineStore.addSeller(s);
    onlineStore.addSeller(s1);

    Product* p = new Product("G843", "Iphone 17", s, 90000);
    Product* p1 = new Product("P375", "Washing Machine", s1, 25000);
    Product* p2 = new Product("T975", "Jacket", s1, 4000);

    std::cout << p->getProductDetail();
    std::cout << p2->getProductDetail();

    Buyer* b = new Buyer("C85I83","Rohan", "Rohan53@outlook.com", 12, "4-Block Civil lines");
    Buyer* b1 = new Buyer("I92X64","Akash", "Akash87@hotmail.com", 58, "35/3 Nala Supara");

    onlineStore.addBuyer(b);
    onlineStore.addBuyer(b1);

    b->addTransactions("TXN_1001982");
    b->addTransactions("TXN_1001983");
    b1->addTransactions("TXN_2004511");

    Order* o = new Order("TE345B64", b);
    o->addProduct(p);
    o->addProduct(p1);
    o->updateStatus("Shipped");

    Order* o1 = new Order("OY572V23", b1);
    o->addProduct(p2);

    onlineStore.addOrder(o);
    onlineStore.addOrder(o1);

    std::cout << onlineStore.getPlatformReport();

    delete s; delete s1;
    delete p; delete p1; delete p2;
    delete b; delete b1;
    delete o; delete o1;


    return 0;
}