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
 *      Last changed: 2012/06/10
 *      HSS version: 1.0
 *      Core version: 0.47
 *      Revision: 1
 *
 ********************************************************************/

#import "HSSFunctionAction.h"
#import "../../axr/AXRController.h"

using namespace AXR;

HSSFunctionAction::HSSFunctionAction()
: HSSAction(HSSActionTypeFunction)
{
    
}

HSSFunctionAction::HSSFunctionAction(const HSSFunctionAction & orig)
: HSSAction(orig.actionType)
{
    //this->_function = orig._function->clone();
}

HSSFunctionAction::p HSSFunctionAction::clone() const
{
    return boost::static_pointer_cast<HSSFunctionAction, HSSClonable>(this->cloneImpl());
}

HSSClonable::p HSSFunctionAction::cloneImpl() const
{
    HSSFunctionAction::p clone = HSSFunctionAction::p(new HSSFunctionAction(*this));
    return clone;
}

HSSFunctionAction::~HSSFunctionAction()
{
    
}


std::string HSSFunctionAction::toString()
{
    return "HSSFunctionAction";
}

std::string HSSFunctionAction::defaultObjectType()
{
    return "value";
}

void HSSFunctionAction::fire()
{
    HSSFunction::p function = this->getFunction();
    function->_evaluate(function->getArguments());
}

HSSFunction::p HSSFunctionAction::getFunction()
{
    return this->_function;
}

void HSSFunctionAction::setFunction(HSSFunction::p newValue)
{
    this->_function = newValue;
}



