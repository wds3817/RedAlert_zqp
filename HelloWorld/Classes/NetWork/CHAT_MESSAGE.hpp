#ifndef CHAT_MESSAGE_hpp
#define CHAT_MESSAGE_hpp


class chat_massage
{
public:
    enum { header_length = 4};
    enum { max_body_length = 20};
    
    chat_massage()
    : body_length_(0)
    {
    }
    
    const char* data() const
    {
        return data_;
    }
    
    char* data()
    {
        return data_;
    }
    
    size_t length() const
    {
        return body_length_ + header_length;
    }
    
    const char * body() const
    {
        return data_ + header_length ;
    }
    
    char * body()
    {
        return data_ + header_length;
    }
    
    size_t body_length() const
    {
        return body_length_;
    }
    
    void body_length(size_t new_length)
    {
        body_length_ = new_length;
        if (body_length_ > max_body_length)
        {
            body_length_ = max_body_length;
        }
    }
    
    bool decode_header()
    {
        using namespace std;
        char header[header_length + 1] = "";
        strncat(header, data_, header_length);
        body_length_ = atoi(header);
        if (body_length_> max_body_length)
        {
            body_length_ = 0;
            return false;
        }
        return true;
    }
    
    void encode_header()
    {
        using namespace std;
        char header[header_length + 1] = "";
        sprintf(header, "%4d",body_length_);
        memcpy(data_, header, header_length);
    }
    
private:
    char data_[header_length + max_body_length];
    size_t body_length_;
};





#endif /* CHAT_MESSAGE_hpp */