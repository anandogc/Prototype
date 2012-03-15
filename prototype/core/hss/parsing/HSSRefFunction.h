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
 *      Last changed: 2012/03/15
 *      HSS version: 1.0
 *      Core version: 0.45
 *      Revision: 3
 *
 ********************************************************************/

#ifndef HSSREFFUNCTION_H
#define HSSREFFUNCTION_H

#include "HSSFunction.h"
#include "../parsing/HSSSelectorChain.h"

namespace AXR {
    class HSSRefFunction : public HSSFunction
    {
    public:
        
        typedef boost::shared_ptr<HSSRefFunction> p;
        
        HSSRefFunction();
        HSSRefFunction(const HSSRefFunction & orig);
        p clone() const;
        virtual ~HSSRefFunction();
        
        const std::string & getModifier() const;
        void setModifier(std::string newValue);
        
        const HSSObservableProperty & getPropertyName() const;
        void setPropertyName(HSSObservableProperty newValue);
        
        const HSSSelectorChain::p & getSelectorChain() const;
        void setSelectorChain(HSSSelectorChain::p newValue);
        
        virtual void * _evaluate();
        virtual void * _evaluate(std::deque<HSSParserNode::p> arguments);
        
        void valueChanged(HSSObservableProperty source, void*data);
        
    private:
        std::string modifier;
        HSSObservableProperty propertyName;
        HSSSelectorChain::p selectorChain;
        
        HSSObservable * observed;
        
        HSSClonable::p cloneImpl() const;
    };
}



#endif