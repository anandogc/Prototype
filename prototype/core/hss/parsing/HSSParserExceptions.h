/********************************************************************
 *             a  A                                                        
 *            AM\/MA                                                         
 *           (MA:MMD                                                         
 *            :: VD
 *           ::  º                                                         
 *          ::                                                              
 *         ::   **      .A$MMMMND   AMMMD     AMMM6    MMMM  MMMM6             
 +       6::Z. TMMM    MMMMMMMMMDA   VMMMD   AMMM6     MMMMMMMMM6            
 *      6M:AMMJMMOD     V     MMMA    VMMMD AMMM6      MMMMMMM6              
 *      ::  TMMTMC         ___MMMM     VMMMMMMM6       MMMM                   
 *     MMM  TMMMTTM,     AMMMMMMMM      VMMMMM6        MMMM                  
 *    :: MM TMMTMMMD    MMMMMMMMMM       MMMMMM        MMMM                   
 *   ::   MMMTTMMM6    MMMMMMMMMMM      AMMMMMMD       MMMM                   
 *  :.     MMMMMM6    MMMM    MMMM     AMMMMMMMMD      MMMM                   
 *         TTMMT      MMMM    MMMM    AMMM6  MMMMD     MMMM                   
 *        TMMMM8       MMMMMMMMMMM   AMMM6    MMMMD    MMMM                   
 *       TMMMMMM$       MMMM6 MMMM  AMMM6      MMMMD   MMMM                   
 *      TMMM MMMM                                                           
 *     TMMM  .MMM                                         
 *     TMM   .MMD       ARBITRARY·······XML········RENDERING                           
 *     TMM    MMA       ====================================                              
 *     TMN    MM                               
 *      MN    ZM                       
 *            MM,
 *
 * 
 *      AUTHORS: Miro Keller
 *      
 *      COPYRIGHT: ©2011 - All Rights Reserved
 *
 *      LICENSE: see License.txt file
 *
 *      WEB: http://axr.vg
 *
 *      THIS CODE AND INFORMATION ARE PROVIDED "AS IS"
 *      WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
 *      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *      IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *      FITNESS FOR A PARTICULAR PURPOSE.
 *
 ********************************************************************
 *
 *      FILE INFORMATION:
 *      =================
 *      Last changed: 2012/05/30
 *      HSS version: 1.0
 *      Core version: 0.47
 *      Revision: 3
 *
 ********************************************************************/

#ifndef HSSPARSEREXCEPTIONS_H
#define HSSPARSEREXCEPTIONS_H

//#include <exception>
#include <string>
#include "../tokenizing/HSSToken.h"

namespace AXR {
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSParserException
    {
    public:
        HSSParserException(std::string filename, int line, int column);
        
        std::string filename;
        int line;
        int column;
        virtual std::string toString();
    };
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSUnexpectedEndOfSourceException : public HSSParserException
    {
    public:
        HSSUnexpectedEndOfSourceException(std::string filename, int line, int column);
        virtual std::string toString();
    };
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSExpectedTokenException : public HSSParserException
    {
    public:
        HSSExpectedTokenException(HSSTokenType type, std::string filename, int line, int column);
        HSSExpectedTokenException(HSSTokenType type, std::string value, std::string filename, int line, int column);
        virtual std::string toString();
        HSSTokenType type;
        std::string value;
    };
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSUnexpectedTokenException : public HSSParserException
    {
    public:
        HSSUnexpectedTokenException(HSSTokenType type, std::string filename, int line, int column);
        HSSUnexpectedTokenException(HSSTokenType type, std::string value, std::string filename, int line, int column);
        virtual std::string toString();
        HSSTokenType type;
        std::string value;
    };
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSUnexpectedObjectTypeException : public HSSParserException
    {
    public:
        HSSUnexpectedObjectTypeException(std::string type, std::string filename, int line, int column);
        virtual std::string toString();
        std::string type;
    };
    
    /**
     *  @brief This class is deprecated. Use AXRError instead.
     *
     *  @todo remove this, and fix any dependency
     */
    class HSSWrongHexLengthException : public HSSParserException
    {
    public:
        HSSWrongHexLengthException(int length, std::string filename, int line, int column);
        virtual std::string toString();
        int length;
    };
}


#endif
