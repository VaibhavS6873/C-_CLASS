// void f()
// {
//     int* ptr = NULL; //raw pointer
//     ptr = new int(100);

//     try
//     {
//         //use ptr
//          g(); //if exception is thrown from here then pointer will not get delete
//             delete ptr;
//         ptr = 0
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
   
   
// }