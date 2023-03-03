#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)) && !defined(B_NOEXCEPTION)
    #define B_THROW0(classname) throw classname()
    #define B_THROW1(classname, msg) throw classname(msg)
    #define B_THROW_DUMP(exception) throw exception
    #define B_TRY try
    #define B_CATCH(exception, handler) catch(exception) handler
#else
    #include <cstdlib>
    #include <iostream>
    #define B_THROW0(classname) do { std::cerr << "Aborting on exception " << #classname << std::endl; std::abort(); } while(false)
    #define B_THROW1(classname, msg) do { std::cerr << "Aborting on exception " << #classname << ": " << (msg) << std::endl; std::abort(); } while(false)
    #define B_THROW_DUMP(exception) do { std::cerr << "Aborting on exception: " << (exception) << std::endl; std::abort(); } while(false)
    #define B_TRY if(true)
    #define B_CATCH(exception, handler)
    #define B_NOEXCEPTION
#endif