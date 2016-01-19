/*
 * This file is part of libArcus
 *
 * Copyright (C) 2016 Ultimaker b.v. <a.hiemstra@ultimaker.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARCUS_MESSAGE_PTR_H
#define ARCUS_MESSAGE_PTR_H

#include <Python.h>
#include "Types.h"

namespace google
{
    namespace protobuf
    {
        class Descriptor;
        class Reflection;
    }
}

namespace Arcus
{
    class PythonMessage
    {
    public:
        PythonMessage(google::protobuf::Message* message);
        PythonMessage(const MessagePtr& message);
        virtual ~PythonMessage();

        std::string getTypeName() const;

        MessagePtr getSharedMessage() const;

        bool hasField(const std::string& field_name);
        PyObject* getField(const std::string& field_name);
        void setField(const std::string& name, PyObject* value);

        PythonMessage* addRepeatedField(const std::string& field_name);
        int repeatedFieldCount(const std::string& field_name);

    private:
        MessagePtr _shared_message;
        google::protobuf::Message* _message;
        const google::protobuf::Reflection* _reflection;
        const google::protobuf::Descriptor* _descriptor;
    };
}

#endif //ARCUS_MESSAGE_PTR_H
