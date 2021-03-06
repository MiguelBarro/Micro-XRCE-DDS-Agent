// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*! 
 * @file SubMessageHeader.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace { char dummy; }
#endif

#include <uxr/agent/types/SubMessageHeader.hpp>
#include <fastcdr/Cdr.h>
#include <fastcdr/exceptions/BadParamException.h>

#include <utility>
#include <type_traits>

using namespace eprosima::fastcdr::exception;

dds::xrce::SubmessageHeader::SubmessageHeader()
{
    m_submessage_id = CREATE_CLIENT;
    m_flags = 0;
    m_submessage_length = 0;
}

dds::xrce::SubmessageHeader::~SubmessageHeader()
{
}

dds::xrce::SubmessageHeader::SubmessageHeader(const SubmessageHeader &x)
{
    m_submessage_id = x.m_submessage_id;
    m_flags = x.m_flags;
    m_submessage_length = x.m_submessage_length;
}

dds::xrce::SubmessageHeader::SubmessageHeader(SubmessageHeader &&x)
{
    m_submessage_id = x.m_submessage_id;
    m_flags = x.m_flags;
    m_submessage_length = x.m_submessage_length;
}

dds::xrce::SubmessageHeader& dds::xrce::SubmessageHeader::operator=(const SubmessageHeader &x)
{
    m_submessage_id = x.m_submessage_id;
    m_flags = x.m_flags;
    m_submessage_length = x.m_submessage_length;
    
    return *this;
}

dds::xrce::SubmessageHeader& dds::xrce::SubmessageHeader::operator=(SubmessageHeader &&x)
{
    m_submessage_id = x.m_submessage_id;
    m_flags = x.m_flags;
    m_submessage_length = x.m_submessage_length;
    
    return *this;
}

size_t dds::xrce::SubmessageHeader::getMaxCdrSerializedSize(size_t current_alignment)
{
    size_t initial_alignment = current_alignment;
            
    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);

    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);

    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    return current_alignment - initial_alignment;
}

size_t dds::xrce::SubmessageHeader::getCdrSerializedSize(const dds::xrce::SubmessageHeader& data, size_t current_alignment)
{
    // TODO.
    (void) data;

    size_t initial_alignment = current_alignment;
            
    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);

    current_alignment += 1 + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);

    current_alignment += 2 + eprosima::fastcdr::Cdr::alignment(current_alignment, 2);


    return current_alignment - initial_alignment;
}

void dds::xrce::SubmessageHeader::serialize(eprosima::fastcdr::Cdr &scdr) const
{
    scdr << static_cast<std::underlying_type<dds::xrce::SubmessageId>::type const&>(m_submessage_id);
    scdr << m_flags;
    scdr.serialize(m_submessage_length, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS);
}

void dds::xrce::SubmessageHeader::deserialize(eprosima::fastcdr::Cdr &dcdr)
{
    std::underlying_type<dds::xrce::SubmessageId>::type temp_underlying_value;
    dcdr >> temp_underlying_value;
    m_submessage_id = static_cast<dds::xrce::SubmessageId>(temp_underlying_value);
    
    dcdr >> m_flags;

    dcdr.deserialize(m_submessage_length, eprosima::fastcdr::Cdr::LITTLE_ENDIANNESS);
}
