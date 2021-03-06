//
//  web.cpp
//  splashkit
//
//  Created by Andrew Cain on 26/07/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#include "web.h"
#include "web_driver.h"
#include "utility_functions.h"
#include <fstream>
#include <cstdio>
#include <cstring>

#include "images.h"

#ifdef WINDOWS
#include <Windows.h>
#endif
namespace splashkit_lib
{
    typedef struct _http_request_data *http_request;

    struct _http_header_data
    {
        string name;
        string value;
    };

    struct _http_request_data
    {
        pointer_identifier id;

        // requestType: HttpMethod;
        string url;
        string version;
        //headername : StringArray;
        //headervalue: StringArray;
        string body;
    };

    struct _http_response_data
    {
        pointer_identifier  id;
        sk_http_response    data;
    };

    sk_http_response make_request (sk_http_method request_type, string url, unsigned short port, string body)
    {
        sk_http_request request;

        request.request_type = request_type;
        request.url = url.c_str();
        request.port = port;
        request.body = body.c_str();

        return sk_http_make_request(request);
    }

    http_response http_get(const string &url, unsigned short port)
    {
        http_response response;

        response = new(_http_response_data);
        response->id = HTTP_RESPONSE_PTR;
        response->data = make_request(HTTP_GET, url, port, "");
        return response;
    }

    http_response http_post(const string &url, unsigned short port, string body)
    {
        http_response response;

        response = new _http_response_data;
        response->id = HTTP_RESPONSE_PTR;
        response->data = make_request(HTTP_POST, url, port, body);
        return response;
    }

    void save_response_to_file(http_response response, string filename)
    {
        ofstream file(filename, ios::binary);
        file.write(response->data.data,response->data.size);
        file.close();
    }

    string http_response_to_string(http_response response)
    {
        if ( ! VALID_PTR(response, HTTP_RESPONSE_PTR))
        {
            LOG(WARNING) << "Attempt to convert invalid http response to a string";
            return "";
        }

        string result = "";

        for (int i = 0; i < response->data.size; i++)
        {
            // WriteLn(response^.data.data[i]);
            result += response->data.data[i];
        }
        return result;
    }

    bool download_file(const string &name, const string &url, unsigned short port, string &path)
    {
        http_response response = http_get(url, port);
        auto cleanup_response = finally( [&] { free_response(response); });

        if ( response->data.status < 200 || response->data.status >= 300 )
        {
            LOG(WARNING) << "Unable to download file from " + url + " got status " + to_string(response->data.status);
            return false;
        }

        char *tmpname;

#ifndef WINDOWS
        tmpname = strdup("/tmp/splashkit.file.XXXXXX");
        mkstemp(tmpname);
#else
        char fname[L_tmpnam];
        tmpnam (fname);
        char tmppath[261] = {0};
        GetTempPath(260, tmppath);

        tmpname = strdup(tmppath);
        string fpath = path_from({tmpname, fname});
        tmpname = strdup(fpath.c_str());
        LOG(WARNING) << tmpname;
#endif
        save_response_to_file(response, tmpname);

        path = string(tmpname);
        free(tmpname);

        return true;
    }

    bitmap download_image(const string &name, const string &url, unsigned short port)
    {
        string path;
        if ( not download_file(name, url, port, path) )
        {
            return nullptr;
        }

        bitmap result = load_bitmap(name, path);
        remove(path.c_str()); // Delete the file
        return result;
    }

    font download_font(const string &name, const string &url, unsigned short port)
    {
        string path;
        if ( not download_file(name, url, port, path) )
        {
            return nullptr;
        }

        font result = load_font(name, path);
        if ( VALID_PTR(result, FONT_PTR) )
            result->was_downloaded = true; // ensure that font will delete file when it is released.
        return result;
    }

    sound_effect download_sound_effect(const string &name, const string &url, unsigned short port)
    {
        string path;
        if ( not download_file(name, url, port, path) )
        {
            return nullptr;
        }

        sound_effect result = load_sound_effect(name, path);
        remove(path.c_str()); // Delete the file
        return result;
    }

    music download_music(const string &name, const string &url, unsigned short port)
    {
        string path;
        if ( not download_file(name, url, port, path) )
        {
            return nullptr;
        }

        music result = load_music(name, path);
        remove(path.c_str()); // Delete the file
        return result;
    }

    void free_response (http_response response)
    {
        if ( VALID_PTR(response, HTTP_RESPONSE_PTR))
        {
            notify_of_free(response);
            sk_free_response(&response->data);
            response->id = NONE_PTR;
            delete(response);
        }
        else
        {
            LOG(WARNING) << "Attempting to delete a http response with an invalid pointer.";
        }
    }
}
